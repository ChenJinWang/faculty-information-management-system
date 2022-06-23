package me.myshop.web.dao;

import java.util.List;

import me.myshop.web.po.Good;

public interface GoodDao {
	// 查询水果
	public List<Good> selectGoodList(Good good);

	public Integer selectGoodListCount(Good good);

	// 上架水果
	public int createGood(Good good);

	// 获取水果并更新
	public Good getGoodById(Integer id);

	public int updateGood(Good good);

	// 删除水果
	public int deleteGood(Integer id);

	// 设置水果
	public int setGood(Integer id);

	// JSON
	public List<Good> selectJSONList(Good good);
}