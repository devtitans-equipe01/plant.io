package devtitans.plantio;

@VintfStability
interface IPlantio {
        int connect();

        int getSoilMoisture();
        int getSoilMoistureInterval();
        boolean setSoilMoistureInterval(in int milliseconds);
        
        int getSoilTemperature();
        int getSoilTemperatureInterval();
        boolean setSoilTemperatureInterval(in int milliseconds);

        int getAmbientMoisture();
        int getAmbientMoistureInterval();
        boolean setAmbientMoistureInterval(in int milliseconds);

        int getAmbientTemperature();
        int getAmbientTemperatureInterval();
        boolean setAmbientTemperatureInterval(in int milliseconds);

        int getAmbientLight();
        int getAmbientLightInterval();
        boolean setAmbientLightInterval(in int milliseconds);
}