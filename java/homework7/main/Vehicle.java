package main;

public abstract class Vehicle {
    protected String Make, Model;
    protected int Year, Weight, TripsSinceMaintenance = 0;
    protected boolean NeedsMaintenance = false;

    protected void Maintenance() {
        if (TripsSinceMaintenance >= 100) {
            NeedsMaintenance = true;
        }
    }

    protected void Repair() {
        NeedsMaintenance = false;
        TripsSinceMaintenance = 0;
    }
}
