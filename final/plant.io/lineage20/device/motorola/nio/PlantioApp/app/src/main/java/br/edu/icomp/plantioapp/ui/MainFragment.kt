package br.edu.icomp.plantioapp.ui

import android.content.Context
import android.os.Bundle
import android.os.RemoteException
import android.util.Log
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.TextView
import android.widget.Toast
import androidx.fragment.app.Fragment
import com.google.android.material.floatingactionbutton.FloatingActionButton
import br.edu.icomp.plantioapp.R
import devtitans.plantiomanager.PlantioManager;

class MainFragment : Fragment() {

    private lateinit var manager : PlantioManager
    private val TAG : String = "DevTitans.Plantio"

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
        return inflater.inflate(R.layout.fragment_main,container,false)
    }

    override fun onViewCreated(view: View, savedInstanceState: Bundle?) {
        super.onViewCreated(view, savedInstanceState)

        try {
            Log.d(TAG, "Estou aqui_Manager ...")
            manager = PlantioManager.getInstance()
        }
        catch(e : NullPointerException){
            Toast.makeText(context, e.message, Toast.LENGTH_LONG).show()
        }
        

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
           txtSMI = it.findViewById(R.id.txt_smi)
           txtSTI = it.findViewById(R.id.txt_sti)
           txtAMI = it.findViewById(R.id.txt_ami)
           txtSTI = it.findViewById(R.id.txt_ati)
           txtALI = it.findViewById(R.id.txt_ali)
           btnUpdate = it.findViewById(R.id.btn_update)
       }

        updateAll()
    }

    override fun onResume() {
        super.onResume()
    }

    fun updateAll() {
        Log.d(TAG, "Atualizando dados do dispositivo ...")
        Toast.makeText(context, "Atualizando", Toast.LENGTH_LONG).show()

        if (manager == null) {
            val soilMoisture: Double = -1.0
            val soilTemperature: Double = -1.0
            val ambientMoisture: Double = -1.0
            val ambientTemperature: Double = -1.0
            val ambientLight: Double = -1.0

            Toast.makeText(context, "Failed to load manager!", Toast.LENGTH_SHORT).show()
            Log.e(TAG, "Failed to load manager!")
            return;
        }

        try {
            val soilMoisture: Double = manager.soilMoisture / 100.0
            val soilTemperature: Double = manager.soilTemperature / 100.0
            val ambientMoisture: Double = manager.ambientMoisture / 100.0
            val ambientTemperature: Double = manager.ambientTemperature / 100.0
            val ambientLight: Double = ((((((manager.ambientLight) / 0.9991) * 0.01) * 100).toLong()).toDouble()) / 100.0

            txtSM.text = "$soilMoisture%"
            txtST.text = "$soilTemperature°C"
            txtAM.text = "$ambientMoisture%"
            txtAT.text = "$ambientTemperature°C"
            txtAL.text = "${ambientLight}%"

            val status = manager.connect()

            if (status == 0) {
                Toast.makeText(context, "Desconectado!", Toast.LENGTH_SHORT).show()
            } else if (status == 1) {
                Toast.makeText(context, "Conectado!", Toast.LENGTH_SHORT).show()
            }
        } catch (e: RemoteException) {
            Toast.makeText(context, "Erro ao acessar o Binder!", Toast.LENGTH_LONG).show()
            Log.e(TAG, "Erro ao atualizar os dados:", e)
        }
    }

    private fun setSoilMoistureInterval(context: Context) {
        try {
            val soilMoistureInterval = txtSMI.text.toString().toInt()
            manager.soilMoistureInterval = soilMoistureInterval
        } catch (e: RemoteException) {
            Toast.makeText(context, "Erro setting the soil moisture update interval!", Toast.LENGTH_LONG).show()
        }
    }

    private fun setSoilTemperatureInterval(context: Context) {
        try {
            val soilTemperatureInterval = txtSTI.text.toString().toInt()
            manager.soilTemperatureInterval = soilTemperatureInterval
        } catch (e: RemoteException) {
            Toast.makeText(context, "Erro setting the soil temperature update interval!", Toast.LENGTH_LONG).show()
        }
    }

    private fun setAmbientMoistureInterval(context: Context) {
        try {
            val ambientMoistureInterval = txtAMI.text.toString().toInt()
            manager.ambientMoistureInterval = ambientMoistureInterval
        } catch (e: RemoteException) {
            Toast.makeText(context, "Erro setting the ambient moisture update interval!", Toast.LENGTH_LONG).show()
        }
    }

    private fun setAmbientTemperatureInterval(context: Context) {
        try {
            val ambientTemperatureInterval = txtATI.text.toString().toInt()
            manager.ambientTemperatureInterval = ambientTemperatureInterval
        } catch (e: RemoteException) {
            Toast.makeText(context, "Erro setting the ambient temperature update interval!", Toast.LENGTH_LONG).show()
        }
    }

    private fun setAmbientLightInterval(context: Context) {
        try {
            val ambientLightInterval = txtALI.text.toString().toInt()
            manager.ambientLightInterval = ambientLightInterval
        } catch (e: RemoteException) {
            Toast.makeText(context, "Erro setting the ambient light update interval!", Toast.LENGTH_LONG).show()
        }
    }
}