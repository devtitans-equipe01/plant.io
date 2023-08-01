package devtitans.plantiomanager;

import android.util.Log;
import android.os.ServiceManager;
import android.os.IBinder;
import android.os.RemoteException;

import devtitans.plantio.IPlantio; // Criado pelo AIDL

public class PlantioManager {
    private static final String TAG = "DevTITANS.PlantioManager";
    private IBinder binder;
    private IPlantio service;

    private static PlantioManager instance;

    // Construtor. Configura a "instância da classe" (objeto) recém-criada.
    // Note o "private" no construtor. Essa classe só pode ser instanciada dentro
    // desse arquivo.
    private PlantioManager() {
        Log.d(TAG, "Nova (única) instância do PlantioManager ...");

        binder = ServiceManager.getService("devtitans.plantio.IPlantio/default");
        if (binder != null) {
            service = IPlantio.Stub.asInterface(binder);
            if (service != null)
                Log.d(TAG, "Serviço Plantio acessado com sucesso.");
            else
                Log.e(TAG, "Erro ao acessar o serviço Plantio!");
        } else
            Log.e(TAG, "Erro ao acessar o Binder!");
    }

    // Acessa a (única) instância dessa classe. Se ela não existir ainda, cria.
    // Note o "static" no método. Podemos executá-lo sem precisar instanciar um
    // objeto.
    public static PlantioManager getInstance() {
        if (instance == null)
            instance = new PlantioManager();

        return instance;
    }

    public int connect() throws RemoteException {
        Log.d(TAG, "Executando método connect() ...");
        return service.connect();
    }

    public int getSoilMoisture() throws RemoteException {
        Log.d(TAG, "Executando método getSoilMoisture() ...");
        return service.getSoilMoisture();
    }

    public int getSoilMoistureInterval() throws RemoteException {
        Log.d(TAG, "Executando método getSoilMoistureInterval() ...");
        return service.getSoilMoistureInterval();
    }

    public boolean setSoilMoistureInterval(int milliseconds) throws RemoteException {
        Log.d(TAG, "Executando método setSoilMoistureInterval(" + milliseconds + ") ...");
        return service.setSoilMoistureInterval(milliseconds);
    }

    public int getSoilTemperature() throws RemoteException {
        Log.d(TAG, "Executando método getSoilTemperature() ...");
        return service.getSoilTemperature();
    }

    public int getSoilTemperatureInterval() throws RemoteException {
        Log.d(TAG, "Executando método getSoilTemperatureInterval() ...");
        return service.getSoilTemperatureInterval();
    }

    public boolean setSoilTemperatureInterval(int milliseconds) throws RemoteException {
        Log.d(TAG, "Executando método setSoilTemperatureInterval(" + milliseconds + ") ...");
        return service.setSoilTemperatureInterval(milliseconds);
    }

    public int getAmbientMoisture() throws RemoteException {
        Log.d(TAG, "Executando método getAmbientMoisture() ...");
        return service.getAmbientMoisture();
    }

    public int getAmbientMoistureInterval() throws RemoteException {
        Log.d(TAG, "Executando método getAmbientMoistureInterval() ...");
        return service.getAmbientMoistureInterval();
    }

    public boolean setAmbientMoistureInterval(int milliseconds) throws RemoteException {
        Log.d(TAG, "Executando método setAmbientMoistureInterval(" + milliseconds + ") ...");
        return service.setAmbientMoistureInterval(milliseconds);
    }

    public int getAmbientTemperature() throws RemoteException {
        Log.d(TAG, "Executando método getAmbientTemperature() ...");
        return service.getAmbientTemperature();
    }

    public int getAmbientTemperatureInterval() throws RemoteException {
        Log.d(TAG, "Executando método getAmbientTemperatureInterval() ...");
        return service.getAmbientTemperatureInterval();
    }

    public boolean setAmbientTemperatureInterval(int milliseconds) throws RemoteException {
        Log.d(TAG, "Executando método setAmbientTemperatureInterval(" + milliseconds + ") ...");
        return service.setAmbientTemperatureInterval(milliseconds);
    }

    public int getAmbientLight() throws RemoteException {
        Log.d(TAG, "Executando método getAmbientLight() ...");
        return service.getAmbientLight();
    }

    public int getAmbientLightInterval() throws RemoteException {
        Log.d(TAG, "Executando método getAmbientLightInterval() ...");
        return service.getAmbientLightInterval();
    }

    public boolean setAmbientLightInterval(int milliseconds) throws RemoteException {
        Log.d(TAG, "Executando método setAmbientLightInterval(" + milliseconds + ") ...");
        return service.setAmbientLightInterval(milliseconds);
    }
}