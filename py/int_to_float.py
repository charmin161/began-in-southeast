
import argparse
import json
import os
import sys
from enum import Enum
from itertools import groupby

import cv2
import numpy as np

if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    
    
    parser.add_argument('--submission_path_int', type=str,
                        default='/path/to/output/test_submission_int.json')
    parser.add_argument('--submission_path_float', type=str,
                        default='/path/to/output/test_submission_float.json')
    opt = parser.parse_args()


    #读取int与float类型文件
    test_submission_int_file = opt.submission_path_int
    test_submission_float_file = opt.submission_path_float
    with open(test_submission_int_file, 'r', encoding='utf-8') as in_file:
        label_info_dict = json.load(in_file)
        #每张图片
        for idx, info in enumerate(label_info_dict.items()):
            image_name, text_info_list = info
            #每个框架
            for index, text_info in enumerate(text_info_list):
                #points的list
                src_point_list = text_info['points']
                #每个坐标保留两位有效数字
                for i in range(len(src_point_list )):
                    src_point_list [i][0] = round(src_point_list [i][0],2)
                    src_point_list [i][1] = round(src_point_list [i][1],2)

                text_info['points'] = src_point_list
                
               

    save_label_json_file = opt.submission_path_float
    with open(save_label_json_file, 'w') as out_file:
        out_file.write(json.dumps(label_info_dict))
            




