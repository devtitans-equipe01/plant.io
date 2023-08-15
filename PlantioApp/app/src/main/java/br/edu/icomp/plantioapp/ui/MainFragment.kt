package br.edu.icomp.plantioapp.ui

import android.os.Bundle
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import androidx.fragment.app.Fragment
import br.edu.icomp.plantioapp.R
import devtitans.plantiomanager.PlantioManager;

class MainFragment : Fragment() {

    private lateinit var  manager : PlantioManager
    override fun onCreateView(
        inflater: LayoutInflater,
        container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View {
        return inflater.inflate(R.layout.fragment_main,container,false)
    }

    override fun onResume() {
        super.onResume()
    }
}