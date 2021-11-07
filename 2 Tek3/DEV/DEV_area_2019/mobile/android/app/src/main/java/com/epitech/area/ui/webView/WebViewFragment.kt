package com.epitech.area.ui.webView

import android.os.Bundle
import android.util.Log
import android.util.Log.d
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.webkit.WebView
import android.webkit.WebViewClient
import androidx.fragment.app.Fragment
import androidx.lifecycle.ViewModelProviders
import com.epitech.area.MainActivity
import com.epitech.area.R


class WebViewFragment : Fragment() {

    private lateinit var webViewViewModel: WebViewViewModel

    override fun onCreateView(
        inflater: LayoutInflater,
        container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {
        webViewViewModel =
            ViewModelProviders.of(this).get(WebViewViewModel::class.java)
        val root = inflater.inflate(R.layout.fragment_webview, container, false)
        Log.d("truc", "webview search")
        val myWebView: WebView = root.findViewById(R.id.webview)
        Log.d("truc", "webview found")
        myWebView.setWebViewClient(object : WebViewClient() {
            override fun shouldOverrideUrlLoading(view: WebView, url: String): Boolean {
                d("truc url : ", url)
                // récup de l'access token etc !!
                MainActivity.prefs!!.accessToken = url.substring(url.indexOf("access_token=") + 13, url.indexOf("&expires_in="))
                MainActivity.prefs!!.imgur_username = url.substring(url.indexOf("&account_username=") + 18, url.indexOf("&account_id="))
                MainActivity.prefs!!.id = url.substring(url.indexOf("&account_id=") + 12)
                d("truc id : ", MainActivity.prefs!!.id)
                d("truc access token : ", MainActivity.prefs!!.accessToken)
                (MainActivity.toolBar.menu.findItem(R.id.imgurSignIn)).isEnabled = false
                MainActivity.prefs!!.is_login_imgur = true
                (MainActivity.toolBar.menu.findItem(R.id.imgurSignIn)).title = MainActivity.prefs!!.imgur_username
                MainActivity.navController.navigate(R.id.nav_home)
                return false
            }
        })
        myWebView.loadUrl("https://api.imgur.com/oauth2/authorize?client_id=da0014568f8064f&response_type=token\n")
        return root
    }
}