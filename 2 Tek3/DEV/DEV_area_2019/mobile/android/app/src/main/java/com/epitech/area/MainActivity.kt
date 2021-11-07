package com.epitech.area

import android.content.Context
import android.content.Intent
import android.content.SharedPreferences
import android.graphics.drawable.Drawable
import android.os.Bundle
import android.util.Log
import android.view.Menu
import android.view.MenuItem
import android.widget.Button
import androidx.appcompat.app.AppCompatActivity
import androidx.appcompat.widget.Toolbar
import androidx.drawerlayout.widget.DrawerLayout
import androidx.navigation.NavController
import androidx.navigation.findNavController
import androidx.navigation.ui.AppBarConfiguration
import androidx.navigation.ui.navigateUp
import androidx.navigation.ui.setupActionBarWithNavController
import androidx.navigation.ui.setupWithNavController
import com.android.volley.Request
import com.android.volley.Response
import com.android.volley.toolbox.StringRequest
import com.android.volley.toolbox.Volley
import com.google.android.gms.auth.api.signin.GoogleSignIn
import com.google.android.gms.auth.api.signin.GoogleSignInAccount
import com.google.android.gms.auth.api.signin.GoogleSignInOptions
import com.google.android.gms.common.api.ApiException
import com.google.android.gms.tasks.Task
import com.google.android.material.navigation.NavigationView
import kotlinx.android.synthetic.main.nav_header_main.*


class MainActivity : AppCompatActivity() {

    private lateinit var appBarConfiguration: AppBarConfiguration
    companion object {
        lateinit var navController: NavController
        lateinit var navView: NavigationView
        lateinit var toolBar: Toolbar
        var prefs: MyPrefs? = null
    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        val toolbar: Toolbar = findViewById(R.id.toolbar)
        setSupportActionBar(toolbar)

        val drawerLayout: DrawerLayout = findViewById(R.id.drawer_layout)
        navView = findViewById(R.id.nav_view)
        navController = findNavController(R.id.nav_host_fragment)
        // Passing each menu ID as a set of Ids because each
        // menu should be considered as top level destinations.
        appBarConfiguration = AppBarConfiguration(
            setOf(
                R.id.nav_home, R.id.nav_gallery, R.id.nav_slideshow, R.id.nav_view
            ), drawerLayout
        )
        setupActionBarWithNavController(navController, appBarConfiguration)
        navView.setupWithNavController(navController)

        toolBar = findViewById(R.id.toolbar)
        prefs = MyPrefs(this)
        prefs!!.is_login = false
    }

    override fun onCreateOptionsMenu(menu: Menu): Boolean {
        // Inflate the menu; this adds items to the action bar if it is present.
        menuInflater.inflate(R.menu.main, menu)
        return true
    }


    private fun googleSignIn() {
        if (GoogleSignIn.getLastSignedInAccount(this) != null) {
            return
        }
        val gso =
            GoogleSignInOptions.Builder(GoogleSignInOptions.DEFAULT_SIGN_IN)
                .requestIdToken(getString(R.string.server_client_id))
                .requestEmail()
                .build()
        val mGoogleSignInClient = GoogleSignIn.getClient(this, gso);
        val signInIntent: Intent = mGoogleSignInClient.signInIntent
        startActivityForResult(signInIntent, 1)
        // This task is always completed immediately, there is no need to attach an
        // asynchronous listener.
    }
    
    private fun ImgurSignIn() {
        val navController = findNavController(R.id.nav_host_fragment)
            if (navController.currentDestination?.id != R.id.nav_view) {
                navController.navigate(R.id.nav_view)
            }
    }

    override fun onActivityResult(requestCode: Int, resultCode: Int, data: Intent?) {
        super.onActivityResult(requestCode, resultCode, data)
        // Result returned from launching the Intent from GoogleSignInClient.getSignInIntent(...);
        if (requestCode == 1) { // The Task returned from this call is always completed, no need to attach
// a listener.
            val task =
                GoogleSignIn.getSignedInAccountFromIntent(data)
            handleSignInResult(task)
        }
    }

    private fun handleSignInResult(completedTask: Task<GoogleSignInAccount>) {
        try {
            val account =
                completedTask.getResult(ApiException::class.java)
            val idToken: String? = account!!.idToken;
            Log.d("truc Token", idToken)

            // Signed in successfully, show authenticated UI.
            val button = findViewById<Button>(R.id.googleSignIn)
            button.text = account.displayName
        } catch (e: ApiException) { // The ApiException status code indicates the detailed failure reason.
// Please refer to the GoogleSignInStatusCodes class reference for more information.
            Log.d(
                "truc",
                "signInResult:failed code=" + e.statusCode
            )
        }
    }

    override fun onOptionsItemSelected(item: MenuItem): Boolean {
        if (item.itemId == R.id.googleSignIn) {
            googleSignIn()
        }
        if (item.itemId == R.id.imgurSignIn) {
            ImgurSignIn()
        }
        return super.onOptionsItemSelected(item)
    }

    override fun onSupportNavigateUp(): Boolean {
        val navController = findNavController(R.id.nav_host_fragment)
        return navController.navigateUp(appBarConfiguration) || super.onSupportNavigateUp()
    }
}

class MyPrefs (context: Context) {
    private val prefsFile = "com.epitech.area.prefs"
    private val prefs: SharedPreferences = context.getSharedPreferences(prefsFile, 0)

    var accessToken: String?
        get() = prefs.getString("accesstoken", null)
        set(value) = prefs.edit().putString("accesstoken", value).apply()
    var username: String?
        get() = prefs.getString("username", null)
        set(value) = prefs.edit().putString("username", value).apply()
    var imgur_username: String?
        get() = prefs.getString("imgur_username", null)
        set(value) = prefs.edit().putString("imgur_username", value).apply()
    var pwd: String?
        get() = prefs.getString("pwd", null)
        set(value) = prefs.edit().putString("pwd", value).apply()
    var id: String?
        get() = prefs.getString("id", null)
        set(value) = prefs.edit().putString("id", value).apply()
    var is_login: Boolean
        get() = prefs.getBoolean("is_login", false)
        set(value) = prefs.edit().putBoolean("is_login", value).apply()
    var is_login_imgur: Boolean
        get() = prefs.getBoolean("is_login_imgur", false)
        set(value) = prefs.edit().putBoolean("is_login_imgur", value).apply()
    var login_state: Int //0: not login, 1: login attempt, 2: logout
        get() = prefs.getInt("login_state", 0)
        set(value) = prefs.edit().putInt("login_state", value).apply()
}

class RefreshImageEvent(var images: Array<Drawable>?, var txt: Array<String>?)
