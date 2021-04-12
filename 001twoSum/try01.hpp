/*************************************************************************
 *	Copyright © 2021 OUC_LiuX, All rights reserved. 
 *	File Name: try01.cpp
 *	Author: OUC_LiuX 	Mail: liuxiang@stu.ouc.edu.cn 
 *	Version: V1.0.0 
 *	Date: 2021-04-12 Mon 16:04
 *	Description: 
 *	History: 
 ************************************************************************/

#include <iostream>
using namespace std;
#include <unordered_map>
#include <random>


class Solution{
	public:
		vector<int> twoSum(vector<int>& nums, int target){
			unordered_map<int, int> hash;
			vector<int> result;
			for (int i = 0; i < nums.size(); i ++){
				if( hash.find(target - nums.at(i)) != hash.end()){
					return {hash.find(target-nums.at(i))->second, i};
					// result.push_back(hash.find(target-nums.at(i))->second);
					// result.push_back(i);
					// return result;
				}
				else{
					hash[nums.at(i)] = i;
				}
			}
			return {-1,-1};
		}
};

