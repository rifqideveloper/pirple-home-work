package main;

public class Cars extends Vehicle {
    private boolean isDriving = false;

    public Cars(String a, String b, int c, int d, int e) {
        super();
        Make = a;
        Model = b;
        Year = c;
        Weight = d;
        TripsSinceMaintenance = e;
        Maintenance();
    }

    public void Stop() {
        isDriving = false;
    }

    public void Drive() {
        Maintenance();
        if (!NeedsMaintenance && TripsSinceMaintenance < 100) {
            isDriving = true;
            TripsSinceMaintenance++;
            Stop();
            Maintenance();
        }

    }

    public void print() {
        System.out.println("------------------------------------------------");
        System.out.println("Make                  : " + Make);
        System.out.println("Model                 : " + Model);
        System.out.println("Year                  : " + Year);
        System.out.println("Weight                : " + Weight + "Kg");
        System.out.println("NeedsMaintenance      : " + NeedsMaintenance);
        System.out.println("TripsSinceMaintenance : " + TripsSinceMaintenance);
    }

}
