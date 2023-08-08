package br.edu.icomp.plantioapp.ui

import android.os.Bundle
import android.view.LayoutInflater
import androidx.appcompat.app.AppCompatActivity
import androidx.core.splashscreen.SplashScreen.Companion.installSplashScreen
import br.edu.icomp.plantioapp.R
import br.edu.icomp.plantioapp.databinding.ActivityMainBinding
import br.edu.icomp.plantioapp.databinding.FragmentMainBinding

class MainActivity : AppCompatActivity() {

    private lateinit var binding: ActivityMainBinding

    override fun onCreate(savedInstanceState: Bundle?) {
        val splashScreen = installSplashScreen()
        super.onCreate(savedInstanceState)
        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)
        setupLayout()
    }

    private fun setupLayout() {

    }
}