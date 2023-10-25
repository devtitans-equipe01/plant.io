package br.edu.icomp.plantioapp.ui

import android.content.Context
import android.content.res.Resources
import android.hardware.Sensor
import android.hardware.SensorEvent
import android.hardware.SensorEventListener
import android.hardware.SensorManager
import android.os.Bundle
import android.os.RemoteException
import android.util.Log
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.ImageView
import android.widget.TextView
import android.widget.Toast
import androidx.fragment.app.Fragment
import br.edu.icomp.plantioapp.R
import com.google.android.material.floatingactionbutton.FloatingActionButton


class MainFragment : Fragment() {

    private var sensorManager: SensorManager? = null
    var sensorListString = ""
    var sensorListString2 = ""

    private val TAG : String = "DevTitans.Plantio"

    private lateinit var imgPlant : ImageView
    private lateinit var imgClimate : ImageView

    private lateinit var txtSM : TextView
    private lateinit var txtST : TextView
    private lateinit var txtAM : TextView
    private lateinit var txtAT : TextView
    private lateinit var txtAL : TextView

    private lateinit var txtSMI : TextView
    private lateinit var txtSTI : TextView
    private lateinit var txtAMI : TextView
    private lateinit var txtATI : TextView
    private lateinit var txtALI : TextView

    private lateinit var btnUpdate : FloatingActionButton

    override fun onCreateView(
        inflater: LayoutInflater,
        container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View {

        val layout : View = inflater.inflate(R.layout.fragment_main,container,false)
        try {
            Log.d(TAG, "Estou aqui_Manager ...")

            sensorManager = context?.getSystemService(Context.SENSOR_SERVICE) as SensorManager?
            setupVariables(layout)
            setupListeners()

        }
        catch(e : NullPointerException){
            Toast.makeText(context, e.message, Toast.LENGTH_LONG).show()
        }
        return layout
    }



    private val listener: SensorEventListener = object : SensorEventListener {
        override fun onSensorChanged(event: SensorEvent) {
            val value = event.values[0]
            txtSM.setText("$value")
        }

        override fun onAccuracyChanged(sensor: Sensor, accuracy: Int) {}
    }


    private val listener2: SensorEventListener = object : SensorEventListener {
        override fun onSensorChanged(event: SensorEvent) {
            val value = event.values[0]
            txtST.setText("$value")
        }

        override fun onAccuracyChanged(sensor: Sensor, accuracy: Int) {}
    }

    private fun setupListeners() {
        btnUpdate.setOnClickListener {
            updateAll()
        }
    }

    private fun showNotConnectedMode(){
        imgPlant.setImageResource(R.drawable.plant_not_connected)
        imgClimate.setImageResource(R.color.gray)
    }

    private fun setupVariables(layout: View) {
        imgPlant = layout.findViewById(R.id.img_plant)
        imgClimate = layout.findViewById(R.id.img_climate)
        txtSM = layout.findViewById(R.id.txt_sm)
        txtST = layout.findViewById(R.id.txt_st)
        txtAM = layout.findViewById(R.id.txt_am)
        txtAT = layout.findViewById(R.id.txt_at)
        txtAL = layout.findViewById(R.id.txt_al)
        txtSMI = layout.findViewById(R.id.txt_smi)
        txtSTI = layout.findViewById(R.id.txt_sti)
        txtAMI = layout.findViewById(R.id.txt_ami)
        txtSTI = layout.findViewById(R.id.txt_ati)
        txtALI = layout.findViewById(R.id.txt_ali)
        btnUpdate = layout.findViewById(R.id.btn_update)

        updateAll()
       }

    fun updateAll() {
        Log.d(TAG, "Atualizando dados do dispositivo ...")
        Toast.makeText(context, "Atualizando", Toast.LENGTH_LONG).show()

        try {

            val sensorList: List<Sensor> = sensorManager?.getSensorList(Sensor.TYPE_LIGHT) as List<Sensor>
            val sensorList2: List<Sensor> = sensorManager?.getSensorList(Sensor.TYPE_AMBIENT_TEMPERATURE) as List<Sensor>

            for (el in sensorList) sensorListString += """ ${el.name} """

            for (el in sensorList2) sensorListString2 += """ ${el.name} """

            Log.println(Log.INFO, "PLANTIO_SENSOR_1", sensorListString)
            Log.println(Log.INFO, "PLANTIO_SENSOR_2", sensorListString2)

            val sensor = sensorList[1]
            sensorManager!!.registerListener(listener, sensor, SensorManager.SENSOR_DELAY_NORMAL)
            val sensor2 = sensorList[1]
            sensorManager!!.registerListener(listener2, sensor2, SensorManager.SENSOR_DELAY_NORMAL)

//            val soilMoisture: Double = 0.0
//            val soilTemperature: Double = 0.0
            val ambientMoisture: Double = 0.0
            val ambientTemperature: Double = 0.0
            val ambientLight: Double = 0.0

//            txtSM.text = "$soilMoisture%"
//            txtST.text = "$soilTemperature°C"
            txtAM.text = "$ambientMoisture%"
            txtAT.text = "$ambientTemperature°C"
            txtAL.text = "$ambientLight%"

        } catch (e: RemoteException) {
            showNotConnectedMode()
            Toast.makeText(context, "Erro ao acessar o Binder!", Toast.LENGTH_LONG).show()
            Log.e(TAG, "Erro ao atualizar os dados:", e)
        } 
    }

    private fun isConnected(){

    }

    override fun onDestroy() {
        super.onDestroy()
        sensorManager?.unregisterListener(listener)
    }
}