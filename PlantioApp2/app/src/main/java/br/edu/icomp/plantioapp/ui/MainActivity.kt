package br.edu.icomp.plantioapp.ui

import android.os.Bundle
import android.os.RemoteException
import android.view.View
import android.util.Log;
import android.widget.*
import androidx.appcompat.app.AppCompatActivity
import androidx.core.splashscreen.SplashScreen.Companion.installSplashScreen
import br.edu.icomp.plantioapp.R
import devtitans.plantiomanager.PlantioManager


class MainActivity : AppCompatActivity() {

    private val TAG = "DevTITANS.PlantioApp"

    private lateinit var txtSM: TextView
    private lateinit var txtST: TextView
    private lateinit var txtAM: TextView
    private lateinit var txtAT: TextView
    private lateinit var txtAL: TextView

    companion object {
        val manager: PlantioManager = PlantioManager.getInstance()
    }

    override fun onCreate(savedInstanceState: Bundle?) {
        installSplashScreen()
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        this.txtSM = findViewById(R.id.txt_sm)
        this.txtST = findViewById(R.id.txt_st)
        this.txtAM = findViewById(R.id.txt_am)
        this.txtAT = findViewById(R.id.txt_at)
        this.txtAL = findViewById(R.id.txt_al)

        this.updateAll(null)
    }

    fun updateAll(view: View?) {
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
            Toast.makeText(this, "Erro ao acessar o Binder!", Toast.LENGTH_LONG).show()
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
//
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