package me.myshop.fragment;

import android.annotation.SuppressLint;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.support.v4.app.Fragment;
import android.support.v4.widget.SwipeRefreshLayout;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.ImageView;
import android.widget.ListView;

import com.google.gson.Gson;
import com.google.gson.reflect.TypeToken;
import com.mzlion.easyokhttp.HttpClient;
import com.youth.banner.Banner;
import com.youth.banner.loader.ImageLoader;

import java.util.ArrayList;
import java.util.List;

import me.myshop.R;
import me.myshop.activity.GoodsDetailActivity;
import me.myshop.adapter.GoodsAdapter;
import me.myshop.common.constant.GoodsTypeEnum;
import me.myshop.common.constant.Mall;
import me.myshop.common.utils.MyData;
import me.myshop.entity.Goods;

public class HomeFragment extends Fragment {
    private View mRootView;

    private static List<Goods> mGoodsList = new ArrayList<>();

    private List<Goods> mSingleTypeGoodsList = new ArrayList<>();

    private GoodsAdapter mGoodsAdapter;

    private SwipeRefreshLayout mSwipeRefreshLayout;

    private String mCurrentType;

    private ListView mListView;

    private int[] id = new int[]{1, 2, 3, 4,5,6};
    private String[] titles = new String[]{"apple1", "litchi1", "orange1", "mango1","dragonfruit1","cherry1"};
    private double[] prices = new double[]{500, 1000, 1500, 2000,2500,3000};
    private int[] images_icon = new int[]{R.drawable.apple1, R.drawable.litchi1, R.drawable.orange1, R.drawable.mango1, R.drawable.dragonfruit1, R.drawable.cherry1};

    private Handler mHandler = new Handler();

    public static HomeFragment newInstance() {
        //获取所有商品数据源
        mGoodsList = MyData.getInstance().getGoodsList();

        Bundle args = new Bundle();
        HomeFragment fragment = new HomeFragment();
        fragment.setArguments(args);
        return fragment;
    }

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setRetainInstance(true);
    }

    @SuppressLint("InflateParams")
    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
        if (mRootView == null){
            mRootView = inflater.inflate(R.layout.fragment_home, null);
        }
        return mRootView;
    }

    @Override
    public void onActivityCreated(Bundle savedInstanceState) {
        super.onActivityCreated(savedInstanceState);

        List<Integer> banner_images= new ArrayList<>();
        banner_images.add(R.drawable.adv_1);
        banner_images.add(R.drawable.adv_2);
        banner_images.add(R.drawable.adv_3);
        banner_images.add(R.drawable.adv_4);
        banner_images.add(R.drawable.adv_5);
        banner_images.add(R.drawable.adv_6);

        Banner banner = getActivity().findViewById(R.id.banner_home);
        banner.setImages(banner_images).setImageLoader(new ImageLoader() {
            @Override
            public void displayImage(Context context, Object path, ImageView imageView) {
                imageView.setImageResource((int)path);
            }
        }).start();

        ImageView iv_apple = getActivity().findViewById(R.id.iv_apple);
        ImageView iv_litchi = getActivity().findViewById(R.id.iv_litchi);
        ImageView iv_orange = getActivity().findViewById(R.id.iv_orange);
        ImageView iv_mango = getActivity().findViewById(R.id.iv_mango);
        ImageView iv_dragonfruit = getActivity().findViewById(R.id.iv_dragonfruit);
        ImageView iv_cherry = getActivity().findViewById(R.id.iv_cherry);


        mSwipeRefreshLayout = getActivity().findViewById(R.id.srf_swipe_refresh);
        mSwipeRefreshLayout.setColorSchemeResources(android.R.color.holo_red_light, android.R.color.holo_orange_light,
                android.R.color.holo_blue_bright, android.R.color.holo_green_light);
        mSwipeRefreshLayout.setOnRefreshListener(new SwipeRefreshLayout.OnRefreshListener() {
            @Override
            public void onRefresh() {

                new Thread(new Runnable() {
                    @Override
                    public void run() {
                        Gson gson = new Gson();

                        //拿到数据库中的所有上架商品
                        String allGoods = HttpClient
                                .get(Mall.BASE_URL + Mall.GOODS_REL_PATH + "/showallgoods")
                                .execute()
                                .asString();

                        List<Goods> goods_list = gson.fromJson(allGoods, new TypeToken<List<Goods>>(){}.getType());
                        if (!goods_list.isEmpty()) {
                            MyData.getInstance().setGoodsList(goods_list);
                        }

                        mHandler.postDelayed(new Runnable() {
                            @Override
                            public void run() {
                                //刷新完成
                                mSwipeRefreshLayout.setRefreshing(false);

                                //更新所有商品数据源
                                mGoodsList = MyData.getInstance().getGoodsList();

                                //获得当前显示的列表类型
                                GoodsTypeEnum goodsType = GoodsTypeEnum.compare(mCurrentType);
                                //取得最新的数据源
                                switchGoodsList(goodsType);
                                //更新列表
                                mGoodsAdapter.notifyDataSetChanged();
                            }
                        }, 4000);

                    }
                }).start();


            }
        });

        View.OnClickListener listener = new MyImageViewClickListener();
        iv_apple.setOnClickListener(listener);
        iv_litchi.setOnClickListener(listener);
        iv_orange.setOnClickListener(listener);
        iv_mango.setOnClickListener(listener);
        iv_dragonfruit.setOnClickListener(listener);
        iv_cherry.setOnClickListener(listener);

//        //匿名用户数据
//        for (int i = 0; i<titles.length; i++) {
//            Goods goods = new Goods();
//            goods.setId(id[i]);
//            goods.setTitle(titles[i]);
//            goods.setPrice(prices[i]);
//            goods.setImageIcon(images_icon[i]);
//            mGoodsList.add(goods);
//        }


        //给cpu列表装载数据
        switchGoodsList(GoodsTypeEnum.apple);


        //初始化ListView控件
        mListView = getActivity().findViewById(R.id.lv_home);
        //创建一个Adapter的实例
        mGoodsAdapter = new GoodsAdapter(mSingleTypeGoodsList, getActivity());
        //设置Adapter
        mListView.setAdapter(mGoodsAdapter);
        mListView.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                Goods goods = (Goods) parent.getAdapter().getItem(position);
                Intent intent_goods_detail = new Intent(getActivity(), GoodsDetailActivity.class);
                intent_goods_detail.putExtra("goods", goods);
                startActivityForResult(intent_goods_detail, 1);
            }
        });


    }

    private void switchGoodsList(GoodsTypeEnum goodsType) {
        mSingleTypeGoodsList.clear();
        for (Goods goods : mGoodsList) {
            if (goods.getType().equals(Integer.valueOf(String.valueOf(goodsType)))) {
                mSingleTypeGoodsList.add(goods);
            }
        }
        mCurrentType = String.valueOf(goodsType);
    }


    private class MyImageViewClickListener implements View.OnClickListener {
        @Override
        public void onClick(View view) {
            switch (view.getId()) {
                case R.id.iv_apple:

                    //给apple列表装载数据
                    switchGoodsList(GoodsTypeEnum.apple);
                    mGoodsAdapter.notifyDataSetChanged();
                    break;
                case R.id.iv_litchi:

                    //给litchi列表装载数据
                    switchGoodsList(GoodsTypeEnum.litchi);
                    mGoodsAdapter.notifyDataSetChanged();
                    break;
                case R.id.iv_orange:

                    //给orange列表装载数据
                    switchGoodsList(GoodsTypeEnum.orange);
                    mGoodsAdapter.notifyDataSetChanged();
                    break;
                case R.id.iv_mango:

                    //给mango列表装载数据
                    switchGoodsList(GoodsTypeEnum.mango);
                    mGoodsAdapter.notifyDataSetChanged();
                    break;
                case R.id.iv_dragonfruit:

                    //给dragonfruit列表装载数据
                    switchGoodsList(GoodsTypeEnum.dragonfruit);
                    mGoodsAdapter.notifyDataSetChanged();
                    break;
                case R.id.iv_cherry:

                    //给cherry列表装载数据
                    switchGoodsList(GoodsTypeEnum.cherry);
                    mGoodsAdapter.notifyDataSetChanged();
                    break;
                default:
                    break;
            }
        }
    }

}

