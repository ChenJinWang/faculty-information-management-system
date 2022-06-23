package me.myshop.common.constant;

public enum GoodsTypeEnum {
    apple("1"),litchi("2"),orange("3"),mango("4"),dragonfruit("5"),cherry("6");

    private String index;

    GoodsTypeEnum(String index) {
        this.index = index;
    }

    public static GoodsTypeEnum compare(String goodsType) {
        if (GoodsTypeEnum.apple.toString().equals(goodsType)) {
            return GoodsTypeEnum.apple;

        } else if (GoodsTypeEnum.litchi.toString().equals(goodsType)) {
            return GoodsTypeEnum.litchi;

        } else if (GoodsTypeEnum.orange.toString().equals(goodsType)) {
            return GoodsTypeEnum.orange;

        } else if (GoodsTypeEnum.mango.toString().equals(goodsType)) {
            return GoodsTypeEnum.mango;

        } else if (GoodsTypeEnum.dragonfruit.toString().equals(goodsType)) {
            return GoodsTypeEnum.dragonfruit;

        } else if (GoodsTypeEnum.cherry.toString().equals(goodsType)) {
            return GoodsTypeEnum.cherry;


        } else {
            return GoodsTypeEnum.cherry;
        }

    }


    @Override
    public String toString() {
        return index;
    }
}
