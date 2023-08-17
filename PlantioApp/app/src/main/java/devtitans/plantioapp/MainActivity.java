package devtitans.plantioapp;

import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.TextView;
import android.widget.Toast;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.splashscreen.SplashScreen;
import devtitans.plantioapp.R.id;

import android.os.RemoteException;
import devtitans.plantiomanager.PlantioManager;

public class MainActivity extends AppCompatActivity {
    private TextView txtSM = null;
    private TextView txtSMI = null;
    private TextView txtST = null;
    private TextView txtSTI = null;
    private TextView txtAM = null;
    private TextView txtAMI = null;
    private TextView txtAT = null;
    private TextView txtATI = null;
    private TextView txtAL = null;
    private TextView txtALI = null;

    private final PlantioManager manager = PlantioManager.getInstance();


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        SplashScreen.Companion.installSplashScreen(this);
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        this.txtSM = findViewById(id.txt_sm);
        this.txtSMI = findViewById(id.txt_smi);
        this.txtST = findViewById(id.txt_st);
        this.txtSTI = findViewById(id.txt_sti);
        this.txtAM = findViewById(id.txt_am);
        this.txtAMI = findViewById(id.txt_ami);
        this.txtAT = findViewById(id.txt_at);
        this.txtATI = findViewById(id.txt_ati);
        this.txtAL = findViewById(id.txt_al);
        this.txtALI = findViewById(id.txt_ali);

        this.updateAll(null);
    }

    public void updateAll(View view) {
        String TAG = "DevTITANS.PlantioApp";
        Log.d(TAG, "Atualizando dados do dispositivo ...");

        try {
            int soilMoisture = this.manager.getSoilMoisture();
            int soilTemperature = this.manager.getSoilTemperature();
            int ambientMoisture = this.manager.getAmbientMoisture();
            int ambientTemperature = this.manager.getAmbientTemperature();
            int ambientLight = this.manager.getAmbientLight();

            this.txtSM.setText(String.valueOf(soilMoisture));
            this.txtST.setText(String.valueOf(soilTemperature));
            this.txtAM.setText(String.valueOf(ambientMoisture));
            this.txtAT.setText(String.valueOf(ambientTemperature));
            this.txtAL.setText(String.valueOf(ambientLight));

            int status = manager.connect();

        } catch (RemoteException e) {
            Toast.makeText(this, "Erro ao acessar o Binder!", Toast.LENGTH_LONG).show();;
            Log.e(TAG, "Erro atualizando dados:", e);
        }
    }

    private void setSoilMoistureInterval(View view) {
       try {
           this.manager.setSoilMoistureInterval(Integer.valueOf(txtSMI.getText().toString()));
       } catch (e: RemoteException) {
           Toast.makeText(this, "Erro setting the soil moisture update interval!", Toast.LENGTH_LONG).show();;
       }
   }

   private void setSoilTemperatureInterval(View view) {
       try {
           this.manager.setSoilTemperatureInterval(Integer.valueOf(txtSTI.getText().toString()));
       } catch (e: RemoteException) {
           Toast.makeText(this, "Erro setting the soil temperature update interval!", Toast.LENGTH_LONG).show();;
       }
   }

   private void setAmbientMoistureInterval(View view) {
       try {
           this.manager.setAmbientMoistureInterval(Integer.valueOf(txtAMI.getText().toString()));
       } catch (e: RemoteException) {
           Toast.makeText(this, "Erro setting the ambient moisture update interval!", Toast.LENGTH_LONG).show();
       }
   }

   private void setAmbientTemperatureInterval(View view) {
       try {
           this.manager.setAmbientTemperatureInterval(Integer.valueOf(txtATI.getText().toString()));
       } catch (e: RemoteException) {
           Toast.makeText(this, "Erro setting the ambient temperature update interval!", Toast.LENGTH_LONG).show();
       }
   }

   private void setAmbientLightInterval(View view) {
       try {
           this.manager.setAmbientLightInterval(Integer.valueOf(txtALI.getText().toString()));
       } catch (e: RemoteException) {
           Toast.makeText(this, "Erro setting the ambient light update interval!", Toast.LENGTH_LONG).show();
       }
   }
}