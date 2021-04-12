/*************************************************************************
 *	Copyright © 2021 OUC_LiuX, All rights reserved. 
 *	File Name: main.cpp
 *	Author: OUC_LiuX 	Mail: liuxiang@stu.ouc.edu.cn 
 *	Version: V1.0.0 
 *	Date: 2021-04-12 Mon 16:13
 *	Description: 
 *	History: 
 ************************************************************************/

#include <iostream>
using namespace std;
#include "try01.hpp"
#include <vector>
#include <random>

int main() {
    Solution solution;
	vector< vector<int>> testdata;
	default_random_engine generator;
	uniform_int_distribution<int> distribution(1,10);

	for (int i = 0; i < 10; i++){
		vector<int> tmp;
		for (int j = 0; j < distribution(generator); j ++){
			tmp.push_back(distribution(generator));
		}
		testdata.push_back(tmp);
	}

	for (int i = 0; i < 10; i ++){
		vector<int> tmp = testdata.at(i);
		vector<int> result;
	    uniform_int_distribution<int> tmpRandom(1, tmp.size());
		int target = tmp.at(tmpRandom(generator)) + tmp.at(tmpRandom(generator));
        result = solution.twoSum(tmp, target);
        printf("%d: %d, %d",target, result.at(0), result.at(1));
	}
}
