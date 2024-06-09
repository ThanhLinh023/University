package com.example.lab2_5;

import android.content.Context;
import android.graphics.drawable.Drawable;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.ImageView;
import android.widget.TextView;
import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import java.util.List;

public class SpinnerAdapter extends BaseAdapter {
    Context context;
    int layoutId;
    List<Dish> dishArr;
    public SpinnerAdapter(Context context, int layoutId, List<Dish> a) {
        super();
        this.context = context;
        this.layoutId = layoutId;
        this.dishArr = a;
    }
    @Override
    public int getCount() {
        return dishArr.size();
    }
    @Override
    public Object getItem(int i) {
        return null;
    }
    @Override
    public long getItemId(int i) {
        return 0;
    }
    @Override
    public View getDropDownView(int position, View convertView, ViewGroup parent) {
        LayoutInflater inflater = (LayoutInflater) context.getSystemService(Context.LAYOUT_INFLATER_SERVICE);
        View row = inflater.inflate(R.layout.dropdown_list, parent, false);
        TextView thbName = row.findViewById(R.id.thumb_text);
        ImageView flag = row.findViewById(R.id.thumb_img);
        Drawable drawable = context.getResources().getDrawable(dishArr.get(position).getThumb());
        thbName.setText(dishArr.get(position).getName());
        flag.setImageDrawable(drawable);
        return row;
    }
    @Override
    public View getView(int position, @Nullable View convertView, @NonNull ViewGroup parent) {
        LayoutInflater inflater = (LayoutInflater) context.getSystemService(Context.LAYOUT_INFLATER_SERVICE);
        View row = inflater.inflate(R.layout.dropdown_list, parent, false);
        TextView thbName = row.findViewById(R.id.thumb_text);
        thbName.setText(dishArr.get(position).getName());
        return row;
    }
}
