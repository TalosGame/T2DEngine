/*!
 * FileName: 	BetterMap.h
 * Copyright:	TalosGame Studio Co., Ltd
 * Data: 		2018/11/07 0:29
 * Author: 		miller
 * Desc:		
 */
 
#ifndef __T2D_ENGINE_BETTER_MAP_H__
#define __T2D_ENGINE_BETTER_MAP_H__

#include <unordered_map>

struct compare
{
	bool operator()(const char* s1, const char* s2) const
	{
		return std::strcmp(s1, s2) == 0;
	}
};

struct hash_func
{
	size_t operator()(const char* str) const
	{
		//BKDR hash algorithm
		int seed = 131;//31  131 1313 13131131313 etc//
		int hash = 0;
		while (*str)
		{
			hash = (hash * seed) + (*str);
			str++;
		}

		return hash & (0x7FFFFFFF);
	}
};

template<class T, class V>
using BetterMap = std::unordered_map<T, V, hash_func, compare>;

template<class T, class V>
bool contains(BetterMap<T, V> *map, T t){
	if (map->find(t) == map->end()){
		return false;
	}

	return true;
}

#endif // __T2D_ENGINE_BETTER_MAP_H__

