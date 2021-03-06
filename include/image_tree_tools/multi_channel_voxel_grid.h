#ifndef MULTI_CHANNEL_VOXEL_GRID_H
#define MULTI_CHANNEL_VOXEL_GRID_H
#include <glog/logging.h>
#include <boost/shared_array.hpp>

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

template <class VALUE>
class MultiChannelVoxelGrid{

protected:
    int _num_classes, _height, _width, _depth;
    boost::shared_array<VALUE> _voxels;

public:
    MultiChannelVoxelGrid(){
        _num_classes = 0;
        _height = 0; 
        _width = 0;
        _depth = 0;
        _voxels = boost::shared_array<VALUE>();
    }

    MultiChannelVoxelGrid(int num_classes, int height, int width, int depth, VALUE default_val=0){
        _num_classes = num_classes;
        _height = height; 
        _width = width;
        _depth = depth;
        long arr_size = _num_classes * _height * _width *_depth;
        _voxels = boost::shared_array<VALUE>(new VALUE[arr_size]);

        if(default_val == 0) memset(_voxels.get(), 0, sizeof(VALUE)* arr_size);
        else{
            for (long i = 0; i <  arr_size; i++) _voxels[i] = default_val;
        }
        

    }

    MultiChannelVoxelGrid(int num_classes, int height, int width, int depth, const VALUE* arr){
        _num_classes = num_classes;
        _height = height; 
        _width = width;
        _depth = depth;
        long arr_size = _num_classes * _height * _width *_depth;
        _voxels = boost::shared_array<VALUE>(new VALUE[arr_size]);

        memcpy(_voxels.get(), arr, sizeof(VALUE)*arr_size);

    }

    long size() {return _num_classes * _height * _width * _depth;}
    int height() {return _height;}
    int width() {return _width;}
    int depth() {return _depth;}
    int num_classes() {return _num_classes; }

    VALUE get_element(int c, int i, int j, int k) {return _voxels[ ((c * _height + i) * _width + j) * _depth + k];}
    void set_element(int c, int i, int j, int k, VALUE val) {_voxels[ ((c * _height + i) * _width + j) * _depth + k] = val;}
    
    bool is_byteorder_big_endian(){
        int num = 1;
        if(*(char *)&num == 1){
            return false;
        }else{
            return true;
        }
    }
    // this function crop the data cost from four corners in suncg, and is deprecated
    // will be removed in future version
    void read_suncg_crop_datacost(string file_name, int num_classes, int crop_mode){

        uint8_t version;
        uint8_t is_big_endian;
        uint8_t uint_size;
        uint32_t elem_size;
        uint32_t height;
        uint32_t width;
        uint32_t depth;
    

        ifstream binaryIo(file_name.c_str(), ios::binary);
        binaryIo.read((char *)(&version), sizeof(version));
        CHECK_EQ(version, 1) 
            <<" version must be 1. ";

        binaryIo.read((char *)(&is_big_endian), sizeof(is_big_endian));
        CHECK((is_big_endian == 1 && is_byteorder_big_endian()) || (is_big_endian == 0 && !is_byteorder_big_endian()))
            << "byteorder must be consistent. ";

    
        binaryIo.read((char *)(&uint_size), sizeof(uint_size));
        CHECK_EQ(uint_size, 4)
            << " uint_size must be 4. ";

    
        binaryIo.read((char *)(&elem_size), sizeof(elem_size));
        CHECK(elem_size == 4 || elem_size == 8)
            << "elem size must be 4 or 8. ";

        binaryIo.read((char *)(&height), sizeof(height));
        binaryIo.read((char *)(&width), sizeof(width));
        binaryIo.read((char *)(&depth), sizeof(depth));
        CHECK_EQ(height % num_classes, 0)
            << "width must be multiple of num_classes .";

        height = height / num_classes;
        int num_elems = width * height * depth * num_classes;


        CHECK_GT(num_elems, 0)
            <<"num_elems must be greater than 0.";
        // crop
        // for suncg datacost, we did not crop the second dimension
        int hstart, hend, dstart, dend;
        int wstart = 0;
        int wend = min(wstart+_width, int(width));

        switch(crop_mode){
            case 0:
                hstart = 0;
                hend = std::min(hstart+_height, int(height));
                dstart = 0;
                dend = std::min(dstart+_depth, int(depth));
                break;
            case 1:
                hend = height;
                hstart = std::max(hend -_height, 0);
                dstart = 0;
                dend = std::min(dstart+_depth, int(depth));
                break;
            case 2:
                hstart = 0;
                hend = std::min(hstart+_height, int(height));
                dend = depth;
                dstart = std::max(dend -_depth, 0);
                break;

            case 3:
                hend = height;
                hstart = std::max(hend -_height, 0);
                dend = depth;
                dstart = std::max(dend -_depth, 0);
                break;
            default:
                LOG(FATAL) << "incorrect crop_mode ";
        }

        
        if(elem_size == 4){
            float* data = new float[num_elems];
            binaryIo.read((char *)(data), num_elems* sizeof(float));
            for(int c = 0; c  < num_classes; c++){
                for(int i = hstart; i < hend; i++){
                    for(int j = wstart; j < wend; j++){
                        for(int k = dstart; k <  dend; k++){
                            set_element(c, i-hstart, j-wstart, k-dstart, data[((c*height + i) * width + j) * depth + k]);
                        }
                    }
                }
            }
            delete [] data;
    
        }else{
            double* data = new double[num_elems];
            binaryIo.read((char *)(data), num_elems* sizeof(double));
            for(int c = 0; c  < num_classes; c++){
                for(int i = hstart; i < hend; i++){
                    for(int j = wstart; j < wend; j++){
                        for(int k = dstart; k <  dend; k++){
                            set_element(c, i-hstart, j-wstart, k-dstart, data[((c*height + i) * width + j) * depth + k]);
                        }
                    }
                }
            }
            delete [] data;
        }

        binaryIo.close();
    }

    void read_datacost(string file_name, int num_classes, const vector<pair<int, int> >& crop){

        uint8_t version;
        uint8_t is_big_endian;
        uint8_t uint_size;
        uint32_t elem_size;
        uint32_t height;
        uint32_t width;
        uint32_t depth;
    

        ifstream binaryIo(file_name.c_str(), ios::binary);
        binaryIo.read((char *)(&version), sizeof(version));
        CHECK_EQ(version, 1) 
            <<" version must be 1. ";

        binaryIo.read((char *)(&is_big_endian), sizeof(is_big_endian));
        CHECK((is_big_endian == 1 && is_byteorder_big_endian()) || (is_big_endian == 0 && !is_byteorder_big_endian()))
            << "byteorder must be consistent. ";

    
        binaryIo.read((char *)(&uint_size), sizeof(uint_size));
        CHECK_EQ(uint_size, 4)
            << " uint_size must be 4. ";

    
        binaryIo.read((char *)(&elem_size), sizeof(elem_size));
        CHECK(elem_size == 4 || elem_size == 8)
            << "elem size must be 4 or 8. ";

        binaryIo.read((char *)(&height), sizeof(height));
        binaryIo.read((char *)(&width), sizeof(width));
        binaryIo.read((char *)(&depth), sizeof(depth));
        CHECK_EQ(height % num_classes, 0)
            << "width must be multiple of num_classes .";

        height = height / num_classes;
        int num_elems = width * height * depth * num_classes;


        CHECK_GT(num_elems, 0)
            <<"num_elems must be greater than 0.";
        // crop
        int hstart = crop[0].first;
        int wstart = crop[1].first;
        int dstart = crop[2].first;

        int hend = crop[0].second;
        int wend = crop[1].second;
        int dend = crop[2].second;
        if(elem_size == 4){
            float* data = new float[num_elems];
            binaryIo.read((char *)(data), num_elems* sizeof(float));
            for(int c = 0; c  < num_classes; c++){
                for(int i = hstart; i < hend; i++){
                    for(int j = wstart; j < wend; j++){
                        for(int k = dstart; k <  dend; k++){
                            set_element(c, i-hstart, j-wstart, k-dstart, data[((c*height + i) * width + j) * depth + k]);
                        }
                    }
                }
            }
            delete [] data;
    
        }else{
            double* data = new double[num_elems];
            binaryIo.read((char *)(data), num_elems* sizeof(double));
            for(int c = 0; c  < num_classes; c++){
                for(int i = hstart; i < hend; i++){
                    for(int j = wstart; j < wend; j++){
                        for(int k = dstart; k <  dend; k++){
                            set_element(c, i-hstart, j-wstart, k-dstart, data[((c*height + i) * width + j) * depth + k]);
                        }
                    }
                }
            }
            delete [] data;
        }

        binaryIo.close();
    }
    void write_datacost(string file_name) {

        uint8_t version = 1;
        uint8_t is_big_endian = is_byteorder_big_endian()? 1:0 ;
        uint8_t uint_size = 4;
        uint32_t elem_size = 4;
        uint32_t height = _height * _num_classes;
        uint32_t width = _width;
        uint32_t depth = _depth;

        ofstream binaryIo(file_name.c_str(), ios::binary);
        binaryIo.write((char *)(&version), sizeof(version));
        binaryIo.write((char *)(&is_big_endian), sizeof(is_big_endian));
        binaryIo.write((char *)(&uint_size), sizeof(uint_size));
    
        binaryIo.write((char *)(&elem_size), sizeof(elem_size));


        binaryIo.write((char *)(&height), sizeof(height));
        binaryIo.write((char *)(&width), sizeof(width));
        binaryIo.write((char *)(&depth), sizeof(depth));  
        long num_elems = width * height * depth;


        float* data = new float[num_elems];
        for(int i = 0; i < num_elems; i++){
            data[i] = _voxels[i];
        }

        binaryIo.write((char *)(data), num_elems* sizeof(float));
        binaryIo.close();

        delete [] data;
    }

    void read_groundtruth_probs(string file_name, const vector<pair<int, int> >& crop){

        uint8_t version;
        uint8_t is_big_endian;
        uint8_t uint_size;
        uint32_t elem_size;
        uint32_t num_classes;
        uint32_t height;
        uint32_t width;
        uint32_t depth;

        ifstream binaryIo(file_name.c_str(), ios::binary);
        binaryIo.read((char *)(&version), sizeof(version));
        CHECK_EQ(version, 1) 
            <<" version must be 1. ";

        binaryIo.read((char *)(&is_big_endian), sizeof(is_big_endian));
        CHECK((is_big_endian == 1 && is_byteorder_big_endian()) || (is_big_endian == 0 && !is_byteorder_big_endian()))
            << "byteorder must be consistent. ";

        binaryIo.read((char *)(&uint_size), sizeof(uint_size));
        CHECK_EQ(uint_size, 4)
            << " uint_size must be 4. ";

        binaryIo.read((char *)(&elem_size), sizeof(elem_size));
        CHECK(elem_size == 4 || elem_size == 8)
            << "elem size must be 4 or 8. ";

        binaryIo.read((char *)(&num_classes), sizeof(num_classes));
        binaryIo.read((char *)(&height), sizeof(height));
        binaryIo.read((char *)(&width), sizeof(width));
        binaryIo.read((char *)(&depth), sizeof(depth));
        
        CHECK_EQ(num_classes, _num_classes) 
            << "num_classes must equal to _num_classes.";

        long num_elems = width * height * depth * num_classes;
        CHECK_GT(num_elems, 0)
            <<"num_elems must be greater than 0.";
        // crop
        int hstart = crop[0].first;
        int wstart = crop[1].first;
        int dstart = crop[2].first;

        int hend = crop[0].second;
        int wend = crop[1].second;
        int dend = crop[2].second;
        if(elem_size == 4){
            float* data = new float[num_elems];
            binaryIo.read((char *)(data), num_elems* sizeof(float));
            for(int c = 0; c  < num_classes; c++){
                for(int i = hstart; i < hend; i++){
                    for(int j = wstart; j < wend; j++){
                        for(int k = dstart; k <  dend; k++){
                            set_element(c, i-hstart, j-wstart, k-dstart, data[((c*height + i) * width + j) * depth + k]);
                        }
                    }
                }
            }
            delete [] data;
    
        }else{
            double* data = new double[num_elems];
            binaryIo.read((char *)(data), num_elems* sizeof(double));
            for(int c = 0; c  < num_classes; c++){
                for(int i = hstart; i < hend; i++){
                    for(int j = wstart; j < wend; j++){
                        for(int k = dstart; k <  dend; k++){
                            set_element(c, i-hstart, j-wstart, k-dstart, data[((c*height + i) * width + j) * depth + k]);
                        }
                    }
                }
            }
            delete [] data;
        }

        binaryIo.close();
    }

    void write_groundtruth_probs(string file_name) {

        uint8_t version = 1;
        uint8_t is_big_endian = is_byteorder_big_endian()? 1:0 ;
        uint8_t uint_size = 4;
        uint32_t elem_size = 4;
        uint32_t num_classes = _num_classes;
        uint32_t height = _height;
        uint32_t width = _width;
        uint32_t depth = _depth;

        ofstream binaryIo(file_name.c_str(), ios::binary);
        binaryIo.write((char *)(&version), sizeof(version));
        binaryIo.write((char *)(&is_big_endian), sizeof(is_big_endian));
        binaryIo.write((char *)(&uint_size), sizeof(uint_size));
    
        binaryIo.write((char *)(&elem_size), sizeof(elem_size));


        binaryIo.write((char *)(&num_classes), sizeof(num_classes));
        binaryIo.write((char *)(&height), sizeof(height));
        binaryIo.write((char *)(&width), sizeof(width));
        binaryIo.write((char *)(&depth), sizeof(depth));  
        long num_elems = width * height * depth * num_classes;


        float* data = new float[num_elems];
        for(int i = 0; i < num_elems; i++){
            data[i] = _voxels[i];
        }

        binaryIo.write((char *)(data), num_elems* sizeof(float));
        binaryIo.close();

        delete [] data;
    }


};



#endif // MULTI_CHANNEL_VOXEL_GRID_H
