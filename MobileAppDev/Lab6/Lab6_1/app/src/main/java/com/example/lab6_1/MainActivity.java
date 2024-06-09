package com.example.lab6_1;

import android.content.Intent;
import android.os.Bundle;
import android.transition.Scene;
import android.util.Log;
import android.view.View;
import android.view.ViewGroup;
import android.view.animation.AccelerateInterpolator;
import android.view.animation.AlphaAnimation;
import android.view.animation.Animation;
import android.view.animation.AnimationUtils;
import android.view.animation.BounceInterpolator;
import android.view.animation.RotateAnimation;
import android.view.animation.ScaleAnimation;
import android.view.animation.TranslateAnimation;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.Toast;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

public class MainActivity extends AppCompatActivity {
    private Button btnFadeInXml, btnFadeInCode, btnFadeOutXml, btnFadeOutCode,
            btnBlinkXml,
            btnBlinkCode, btnZoomInXml, btnZoomInCode, btnZoomOutXml,
            btnZoomOutCode, btnRotateXml,
            btnRotateCode, btnMoveXml, btnMoveCode, btnSlideUpXml, btnSlideUpCode,
            btnBounceXml, btnBack,
            btnBounceCode, btnCombineXml, btnCombineCode;
    private ImageView ivUitLogo;
    private Animation.AnimationListener animationListener;
    private Scene aScence;
    private ViewGroup root;
    private void findViewsByIds() {
        ivUitLogo = (ImageView) findViewById(R.id.iv_uit_logo);
        btnFadeInXml = (Button) findViewById(R.id.btn_fade_in_xml);
        btnFadeInCode = (Button) findViewById(R.id.btn_fade_in_code);
        btnFadeOutXml = (Button) findViewById(R.id.btn_fade_out_xml);
        btnFadeOutCode = (Button) findViewById(R.id.btn_fade_out_code);
        btnBlinkXml = (Button) findViewById(R.id.btn_blink_xml);
        btnBlinkCode = (Button) findViewById(R.id.btn_blink_code);
        btnZoomInXml = (Button) findViewById(R.id.btn_zoom_in_xml);
        btnZoomInCode = (Button) findViewById(R.id.btn_zoom_in_code);
        btnZoomOutXml = (Button) findViewById(R.id.btn_zoom_out_xml);
        btnZoomOutCode = (Button) findViewById(R.id.btn_zoom_out_code);
        btnRotateXml = (Button) findViewById(R.id.btn_rotate_xml);
        btnRotateCode = (Button) findViewById(R.id.btn_rotate_code);
        btnMoveXml = (Button) findViewById(R.id.btn_move_xml);
        btnMoveCode = (Button) findViewById(R.id.btn_move_code);
        btnSlideUpXml = (Button) findViewById(R.id.btn_slide_up_xml);
        btnSlideUpCode = (Button) findViewById(R.id.btn_slide_up_code);
        btnBounceXml = (Button) findViewById(R.id.btn_bounce_xml);
        btnBounceCode = (Button) findViewById(R.id.btn_bounce_code);
        btnCombineXml = (Button) findViewById(R.id.btn_combine_xml);
        btnCombineCode = (Button) findViewById(R.id.btn_combine_code);
        btnBack = (Button) findViewById(R.id.btn_back);
    }
    private void initVariables() {
        animationListener = new Animation.AnimationListener() {
            @Override
            public void onAnimationStart(Animation animation) {
            }
            @Override
            public void onAnimationEnd(Animation animation) {
                Toast.makeText(getApplicationContext(), "Animation Stopped", Toast.LENGTH_SHORT).show();
            }
            @Override
            public void onAnimationRepeat(Animation animation) {
            }
        };
    }
    private void handleOnAnimationXML(Button btn, int animId)
    {
        final Animation animation = AnimationUtils.loadAnimation(MainActivity.this, animId);
        animation.setAnimationListener(animationListener);
        btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                ivUitLogo.startAnimation(animation);
            }
        });
    }
    private void handleOnAnimationCode(Button btn, final Animation a)
    {
        btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                ivUitLogo.startAnimation(a);
            }
        });
    }
    private Animation fadeIn()
    {
        AlphaAnimation animation = new AlphaAnimation(0, 1);
        animation.setInterpolator(new AccelerateInterpolator());
        animation.setDuration(2000);
        animation.setFillAfter(true);
        animation.setAnimationListener(animationListener);
        return animation;
    }
    private Animation fadeOut()
    {
        AlphaAnimation animation = new AlphaAnimation(1, 0);
        animation.setInterpolator(new AccelerateInterpolator());
        animation.setDuration(2000);
        animation.setFillAfter(true);
        animation.setAnimationListener(animationListener);
        return animation;
    }
    private Animation blink()
    {
        AlphaAnimation animation = new AlphaAnimation(1, 0);
        animation.setInterpolator(new AccelerateInterpolator());
        animation.setDuration(500);
        animation.setRepeatCount(Animation.INFINITE);
        animation.setFillAfter(true);
        animation.setAnimationListener(animationListener);
        return animation;
    }
    private Animation zoomIn()
    {
        ScaleAnimation animation = new ScaleAnimation(
                1.0f, 2.5f,
                1.0f, 2.5f,
                Animation.RELATIVE_TO_SELF, 0.5f,
                Animation.RELATIVE_TO_SELF, 0.5f
        );
        animation.setInterpolator(new AccelerateInterpolator());
        animation.setDuration(3000);
        return animation;
    }
    private Animation zoomOut()
    {
        ScaleAnimation animation = new ScaleAnimation(
                1.0f, 0.5f,
                1.0f, 0.5f,
                Animation.RELATIVE_TO_SELF, 0.5f,
                Animation.RELATIVE_TO_SELF, 0.5f
        );
        animation.setInterpolator(new AccelerateInterpolator());
        animation.setDuration(3000);
        return animation;
    }
    private Animation rotate()
    {
        RotateAnimation animation = new RotateAnimation(
                0.0f, 360.0f,
                Animation.RELATIVE_TO_SELF, 0.5f,
                Animation.RELATIVE_TO_SELF, 0.5f
        );
        animation.setInterpolator(new AccelerateInterpolator());
        animation.setDuration(3000);
        return animation;
    }
    private Animation move()
    {
        TranslateAnimation translateAnimation = new TranslateAnimation(
                Animation.RELATIVE_TO_PARENT, 0.0f,
                Animation.RELATIVE_TO_PARENT, 1.0f,
                Animation.RELATIVE_TO_PARENT, 0.0f,
                Animation.RELATIVE_TO_PARENT, 0.0f
        );
        translateAnimation.setDuration(1000);
        translateAnimation.setInterpolator(new AccelerateInterpolator());
        translateAnimation.setDuration(3000);
        return translateAnimation;
    }
    private Animation slideUp()
    {
        TranslateAnimation translateAnimation = new TranslateAnimation(
                Animation.RELATIVE_TO_PARENT, 0.0f,
                Animation.RELATIVE_TO_PARENT, 0.0f,
                Animation.RELATIVE_TO_PARENT, 0.0f,
                Animation.RELATIVE_TO_PARENT, -1.0f
        );
        translateAnimation.setDuration(500);
        translateAnimation.setInterpolator(new AccelerateInterpolator());
        translateAnimation.setFillAfter(true);
        return translateAnimation;
    }
    private Animation bounce()
    {
        TranslateAnimation translateAnimation = new TranslateAnimation(
                Animation.RELATIVE_TO_PARENT, 0.0f,
                Animation.RELATIVE_TO_PARENT, 0.0f,
                Animation.RELATIVE_TO_PARENT, 0.0f,
                Animation.RELATIVE_TO_PARENT, 0.5f
        );
        translateAnimation.setInterpolator(new AccelerateInterpolator());
        translateAnimation.setDuration(1000);
        translateAnimation.setInterpolator(new BounceInterpolator());
        translateAnimation.setFillAfter(true);

        return translateAnimation;
    }
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_main);
        findViewsByIds();
        initVariables();
        // Animation from XML
        handleOnAnimationXML(btnFadeInXml, R.anim.anim_fade_in);
        handleOnAnimationXML(btnFadeOutXml, R.anim.anim_fade_out);
        handleOnAnimationXML(btnBlinkXml, R.anim.anim_blink);
        handleOnAnimationXML(btnZoomInXml, R.anim.anim_zoom_in);
        handleOnAnimationXML(btnZoomOutXml, R.anim.anim_zoom_out);
        handleOnAnimationXML(btnRotateXml, R.anim.anim_rotate);
        handleOnAnimationXML(btnMoveXml, R.anim.anim_move);
        handleOnAnimationXML(btnSlideUpXml, R.anim.anim_slide_up);
        handleOnAnimationXML(btnBounceXml, R.anim.anim_bounce);
        // Animation from code
        handleOnAnimationCode(btnFadeInCode, fadeIn());
        handleOnAnimationCode(btnFadeOutCode, fadeOut());
        handleOnAnimationCode(btnBlinkCode, blink());
        handleOnAnimationCode(btnZoomInCode, zoomIn());
        handleOnAnimationCode(btnZoomOutCode, zoomOut());
        handleOnAnimationCode(btnRotateCode, rotate());
        handleOnAnimationCode(btnMoveCode, move());
        handleOnAnimationCode(btnSlideUpCode, slideUp());
        handleOnAnimationCode(btnBounceCode, bounce());
        ivUitLogo.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                try {
                    Intent iNewActivity = new Intent(MainActivity.this, Main2Activity.class);
                    startActivity(iNewActivity);
                    overridePendingTransition(R.anim.anim_move_in, R.anim.anim_move_out);
                }
                catch (Exception e)
                {
                    Log.w("logo_clic", e.getMessage());
                }
            }
        });
    }
}