package br.edu.icomp.plantioapp.ui

import android.os.Bundle
import android.os.RemoteException
import android.util.Log
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.TextView
import android.widget.Toast
import androidx.fragment.app.Fragment
import br.edu.icomp.plantioapp.R
import com.google.android.material.floatingactionbutton.FloatingActionButton
import devtitans.plantiomanager.PlantioManager;

class MainFragment : Fragment() {

    private lateinit var manager : PlantioManager
    private val TAG : String = "DevTitans.Plantio"

    private lateinit var txtSM : TextView
    private lateinit var txtST : TextView
    private lateinit var txtAM : TextView
    private lateinit var txtAT : TextView
    private lateinit var txtAL : TextView

    private lateinit var btnUpdate : FloatingActionButton

    override fun onCreateView(
        inflater: LayoutInflater,
        container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View {
        return inflater.inflate(R.layout.fragment_main,container,false)
    }

    override fun onViewCreated(view: View, savedInstanceState: Bundle?) {
        super.onViewCreated(view, savedInstanceState)

        manager = PlantioManager.getInstance()

        setupVariables()
        setupListeners()
        
    }

    private fun setupListeners() {
        btnUpdate.setOnClickListener {
            updateAll()
        }
    }

    private fun setupVariables() {
       view?.let {
           txtSM = it.findViewById(R.id.txt_sm)
           txtST = it.findViewById(R.id.txt_st)
           txtAM = it.findViewById(R.id.txt_am)
           txtAT = it.findViewById(R.id.txt_at)
           txtAL = it.findViewById(R.id.txt_al)
           btnUpdate = it.findViewById(R.id.btn_update)
       }

        updateAll()
    }

    override fun onResume() {
        super.onResume()
    }

    fun updateAll() {
        Log.d(TAG, "Atualizando dados do dispositivo ...")
//        textStatus.text = "Atualizando ..."
//        textStatus.setTextColor(Color.parseColor("#c47e00"))

        try {
            val soilMoisture: Int = manager.soilMoisture
            val soilTemperature: Int = manager.soilTemperature
            val ambientMoisture: Int = manager.ambientMoisture
            val ambientTemperature: Int = manager.ambientTemperature
            val ambientLight: Int = manager.ambientLight

            txtSM.text = soilMoisture.toString()
            txtST.text = soilTemperature.toString()
            txtAM.text = ambientMoisture.toString()
            txtAT.text = ambientTemperature.toString()
            txtAL.text = ambientLight.toString()

            val status = manager.connect()

//            if (status == 0) {
//                textStatus.text = "Desconectado"
//                textStatus.setTextColor(Color.parseColor("#73312f"))
//            } else if (status == 1) {
//                textStatus.text = "Conectado"
//                textStatus.setTextColor(Color.parseColor("#6d790c"))
//            }
        } catch (e: RemoteException) {
            Toast.makeText(context, "Erro ao acessar o Binder!", Toast.LENGTH_LONG).show()
            Log.e(TAG, "Erro atualizando dados:", e)
        }
    }

//    private fun setSoilMoistureInterval(view: View?) {
//        try {
//            val soilMoistureInterval = textFieldSoilMoistureInterval.text.toString().toInt()
//            manager.soilMoistureInterval = soilMoistureInterval
//        } catch (e: RemoteException) {
//            Toast.makeText(this, "Erro setting the soil moisture update interval!", Toast.LENGTH_LONG).show()
//        }
//    }

//    private fun setSoilTemperatureInterval(view: View?) {
//        try {
//            val soilTemperatureInterval = textFieldSoilTemperatureInterval.text.toString().toInt()
//            manager.soilTemperatureInterval = soilTemperatureInterval
//        } catch (e: RemoteException) {
//            Toast.makeText(this, "Erro setting the soil temperature update interval!", Toast.LENGTH_LONG).show()
//        }
//    }
//
//    private fun setAmbientMoistureInterval(view: View?) {
//        try {
//            val ambientMoistureInterval = textFieldAmbientMoistureInterval.text.toString().toInt()
//            manager.ambientMoistureInterval = ambientMoistureInterval
//        } catch (e: RemoteException) {
//            Toast.makeText(this, "Erro setting the ambient moisture update interval!", Toast.LENGTH_LONG).show()
//        }
//    }
//
//    private fun setAmbientTemperatureInterval(view: View?) {
//        try {
//            val ambientTemperatureInterval = textFieldAmbientTemperatureInterval.text.toString().toInt()
//            manager.ambientTemperatureInterval = ambientTemperatureInterval
//        } catch (e: RemoteException) {
//            Toast.makeText(this, "Erro setting the ambient temperature update interval!", Toast.LENGTH_LONG).show()
//        }
//    }
//
//    private fun setAmbientLightInterval(view: View?) {
//        try {
//            val ambientLightInterval = textFieldAmbientLightInterval.text.toString().toInt()
//            manager.ambientLightInterval = ambientLightInterval
//        } catch (e: RemoteException) {
//            Toast.makeText(this, "Erro setting the ambient light update interval!", Toast.LENGTH_LONG).show()
//        }
//    }
}