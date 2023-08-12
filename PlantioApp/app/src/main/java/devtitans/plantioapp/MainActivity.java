package devtitans.plantioapp;

import android.os.Bundle;
import android.os.RemoteException;
import android.util.Log;
import android.view.View;
import android.widget.TextView;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;
import androidx.core.splashscreen.SplashScreen;
import devtitans.plantioapp.R.id;
import devtitans.plantiomanager.PlantioManager;

public class MainActivity extends AppCompatActivity {

    private TextView txtSM = null;
    private TextView txtST = null;
    private TextView txtAM = null;
    private TextView txtAT = null;
    private TextView txtAL = null;

    private final PlantioManager manager = PlantioManager.getInstance();


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        SplashScreen.Companion.installSplashScreen(this);
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        this.txtSM = findViewById(id.txt_sm);
        this.txtST = findViewById(id.txt_st);
        this.txtAM = findViewById(id.txt_am);
        this.txtAT = findViewById(id.txt_at);
        this.txtAL = findViewById(id.txt_al);

        this.updateAll(null);
    }

    public void updateAll(View view) {
        String TAG = "DevTITANS.PlantioApp";
        Log.d(TAG, "Atualizando dados do dispositivo ...");
//        textStatus.text = "Atualizando ..."
//        textStatus.setTextColor(Color.parseColor("#c47e00"))

        try {
            int soilMoisture = this.manager.getSoilMoisture();
            int soilTemperature = this.manager.getSoilTemperature();
            int ambientMoisture = this.manager.getAmbientMoisture();
            int ambientTemperature = this.manager.getAmbientTemperature();
            int ambientLight = this.manager.getAmbientLight();

            this.txtSM.setText(String.valueOf(soilMoisture));
            txtST.setText(String.valueOf(soilTemperature));
            txtAM.setText(String.valueOf(ambientMoisture));
            txtAT.setText(String.valueOf(ambientTemperature));
            txtAL.setText(String.valueOf(ambientLight));

            int status = manager.connect();

//            if (status == 0) {
//                textStatus.text = "Desconectado"
//                textStatus.setTextColor(Color.parseColor("#73312f"))
//            } else if (status == 1) {
//                textStatus.text = "Conectado"
//                textStatus.setTextColor(Color.parseColor("#6d790c"))
//            }
        } catch (RemoteException e) {
            Toast.makeText(this, "Erro ao acessar o Binder!", Toast.LENGTH_LONG).show();
            Log.e(TAG, "Erro atualizando dados:", e);
        }
    }
}