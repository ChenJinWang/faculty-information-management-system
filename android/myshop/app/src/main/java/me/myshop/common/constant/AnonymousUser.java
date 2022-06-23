package me.myshop.common.constant;



import me.myshop.R;
import me.myshop.entity.Goods;

import java.util.List;

public class AnonymousUser {
    private static int[] id = {1,2, 3, 4, 5, 6, 7, 8, 9};
    private static int[] number = {1, 2, 3, 4, 5, 6, 7, 8};
    private static String[] titles = {"apple1", "litchi1", "orange1", "mango1","dragonfruit1","cherry1", "红富士   1公斤", "三月红   1公斤", "沙糖桔   1公斤",
            "水仙芒   1公斤","红心火龙果 1公斤","红灯     1公斤"};
    private static double[] prices = {500, 1000, 1500, 2000, 389, 289, 579, 888};
    private static int[] images_icon = {R.drawable.apple1, R.drawable.litchi1,
            R.drawable.orange1, R.drawable.mango1, R.drawable.dragonfruit1, R.drawable.cherry1};

    public static void LoadingData(List<Goods> mGoodsList) {
        for (int i = 0; i < titles.length; i++) {
            Goods goods = new Goods();
            goods.setId(id[i]);
            goods.setTitle(titles[i]);
            goods.setPrice(prices[i]);
//            goods.setImageIcon(images_icon[i]);
            goods.setNumber(number[i]);
            mGoodsList.add(goods);
        }
    }
}
