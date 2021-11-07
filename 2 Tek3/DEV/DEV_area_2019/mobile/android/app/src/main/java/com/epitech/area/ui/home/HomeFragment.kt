package com.epitech.area.ui.home

import android.os.Bundle
import android.util.Log
import android.view.*
import android.webkit.WebView
import android.webkit.WebViewClient
import android.widget.Button
import android.widget.TextView
import androidx.appcompat.widget.Toolbar
import androidx.core.view.isVisible
import androidx.fragment.app.Fragment
import androidx.lifecycle.Observer
import androidx.lifecycle.ViewModelProviders
import androidx.navigation.NavController
import com.android.volley.AuthFailureError
import com.android.volley.Request
import com.android.volley.Response
import com.android.volley.toolbox.StringRequest
import com.android.volley.toolbox.Volley
import com.epitech.area.R
import com.epitech.area.MainActivity
import com.epitech.area.MyPrefs
import com.google.android.material.navigation.NavigationView
import com.google.android.material.textfield.TextInputLayout
import kotlinx.android.synthetic.main.nav_header_main.*
import org.w3c.dom.Text

class HomeFragment : Fragment(), View.OnClickListener {

    private lateinit var homeViewModel: HomeViewModel
    companion object {
        var prefs: MyPrefs? = null
    }

    override fun onCreateView(
        inflater: LayoutInflater,
        container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {
        homeViewModel =
            ViewModelProviders.of(this).get(HomeViewModel::class.java)
        val root = inflater.inflate(R.layout.fragment_home, container, false)
        val textView: TextView = root.findViewById(R.id.text_home)
        homeViewModel.text.observe(this, Observer {
            textView.text = it
        })

        val fab: Button = root.findViewById(R.id.fab)
        fab.setOnClickListener(this)
        Log.d("Home", "listening.....")
        prefs = MyPrefs(this.context!!)

        if (prefs!!.login_state == 1) {
            prefs!!.login_state == 0
        }
        if (prefs!!.login_state == 2) {
            fab.text = getString(R.string.areaSignOut)
        }

        return root
    }

    override fun onClick(v: View?) {
        when (v?.id) {
            R.id.fab -> {
                if (prefs!!.login_state == 0) {
                    view!!.findViewById<TextInputLayout>(R.id.textInputLayout2).visibility = View.VISIBLE
                    view!!.findViewById<TextInputLayout>(R.id.textInputLayout3).visibility = View.VISIBLE
                    view!!.findViewById<Button>(R.id.fab).text = getString(R.string.Submit_button)
                    prefs!!.login_state = 1
                } else if (prefs!!.login_state == 1)
                {
                    prefs!!.username = view!!.findViewById<TextInputLayout>(R.id.textInputLayout2).editText!!.text.toString()
                    prefs!!.pwd = view!!.findViewById<TextInputLayout>(R.id.textInputLayout3).editText!!.text.toString()
                    val queue = Volley.newRequestQueue(this.context)
                    val url: String = getString(R.string.server_url) + "api/v1/entrance/login/"
                    Log.d("Home", "requested")
                    val stringRequest = object: StringRequest(
                        Request.Method.PUT, url,
                        Response.Listener<String> { response ->
                            view!!.findViewById<TextInputLayout>(R.id.textInputLayout2).visibility = View.GONE
                            view!!.findViewById<TextInputLayout>(R.id.textInputLayout3).visibility = View.GONE
                            view!!.findViewById<TextInputLayout>(R.id.textInputLayout3).editText!!.text.clear()
                            view!!.findViewById<Button>(R.id.fab).text = getString(R.string.areaSignOut)
                            prefs!!.login_state = 2
                            prefs!!.is_login = true
                            Log.d("Home", response.substring(0, 500))
                        },
                        Response.ErrorListener {
                            //textView.text = "That didn't work!"
                            Log.d("Home", "No response")
                        }) {
                        override fun getParams(): Map<String, String> {
                        val params = HashMap<String, String>()
                            prefs!!.username?.let { params.put("username", it) }
                            prefs!!.pwd?.let { params.put("pwd", it) }
                        return params
                        }
                    }
                    queue.add(stringRequest)
                    view!!.findViewById<TextInputLayout>(R.id.textInputLayout2).visibility = View.GONE
                    view!!.findViewById<TextInputLayout>(R.id.textInputLayout3).visibility = View.GONE
                    view!!.findViewById<TextInputLayout>(R.id.textInputLayout3).editText!!.text.clear()
                    view!!.findViewById<Button>(R.id.fab).text = getString(R.string.areaSignOut)
                    prefs!!.login_state = 2
                    prefs!!.is_login = true
                } else
                {
                    val queue = Volley.newRequestQueue(this.context)
                    val url: String = getString(R.string.server_url) + "logout/"
                    val stringRequest = StringRequest(
                        Request.Method.GET, url,
                        Response.Listener<String> { response ->
                            Log.d("Home", response)
                        },
                        Response.ErrorListener {
                            Log.d("Home", "No response")
                        })
                    queue.add(stringRequest)
                    prefs!!.is_login = false
                    prefs!!.username = null
                    prefs!!.pwd = null
                    prefs!!.login_state = 0
                    view!!.findViewById<Button>(R.id.fab).text = getString(R.string.areaSignIn)
                }
            }
            else -> {
            }
        }
    }
}