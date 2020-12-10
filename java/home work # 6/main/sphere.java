package main;

public class sphere {
    private final double volume,surface_area,circumference,diameter;
    public sphere(double radius){
        diameter= 2 * radius;
        volume= (4*22*radius*radius*radius)/(3*7);
        surface_area = 4 * Math.PI * radius * radius;
        circumference= Math.PI * 2*radius;
    }
    public void print_volume(){
        System.out.println("volume : " + volume);
    }
    public void print_surface_area(){
        System.out.println("surface area : "+surface_area);
    }
    public void print_circumference(){
        System.out.println("circumference : "+circumference);
    }
    public void print_diameter(){
        System.out.println("diameter : "+diameter);
    }
}
