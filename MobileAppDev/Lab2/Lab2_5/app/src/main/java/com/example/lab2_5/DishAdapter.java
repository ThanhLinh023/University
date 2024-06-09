package com.example.lab2_5;

import android.app.Activity;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.ImageView;
import android.widget.TextView;

import java.util.List;

public class DishAdapter extends ArrayAdapter<Dish> {
    private Activity context;
    public DishAdapter(Activity context, int layoutId, List<Dish> obj)
    {
        super(context, layoutId, obj);
        this.context = context;
    }
    @Override
    public View getView(final int position, View convertView, ViewGroup parent)
    {
        if (convertView == null) {
            convertView = LayoutInflater.from(context).inflate(R.layout.dish_in_gridview, null, false);
        }

        Dish d = getItem(position);
        ImageView dishImg = (ImageView) convertView.findViewById(R.id.dish_img);
        TextView dishText = (TextView) convertView.findViewById(R.id.dish_name);
        dishText.setSelected(true);
        ImageView icnStar = (ImageView) convertView.findViewById(R.id.star);

        if (d.isPro())
        {
            icnStar.setVisibility(View.VISIBLE);

        }
        else
        {
            icnStar.setVisibility(View.GONE);
        }
        dishImg.setImageResource(d.getThumb());
        dishText.setText(d.getName());
        return convertView;
    }
}
