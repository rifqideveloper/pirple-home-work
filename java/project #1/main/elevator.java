package main;

public class elevator {
    public int min, max;
    private int elevator_location = 0;
    private boolean door_open = true,emergency = false;
    private final String name;
    public void sleep(){
        try {
            Thread.sleep(1000);
        } catch (InterruptedException ex) {
            Thread.currentThread().interrupt();

        }
    }
    public void reset(){
        door_open = false;
        emergency = false;

    }
    public void emergency_button(){
        if (elevator_location == min){
            moveup();
        }else {
            movedown();
        }
        door_open = true;
        emergency = true;
    }
    public void elevator_door(){
        if(door_open && !emergency){
            door_open = false;
            System.out.println(name + ":" + "close door");
        }else {
            door_open = true;
            System.out.println(name + ":" + "open door");
        }
    }
    public elevator(int m, int x, String n) {
        min = m;
        max = x;
        name = n;
    }

    public void print() {
        System.out.println(name + ":" + elevator_location);
    }

    public void moveup() {
        if (elevator_location != max && !emergency) {
            elevator_location++;
            sleep();
            print();
        }
    }
    public void moveup(int from) {
        if (elevator_location != max && elevator_location != from && !emergency) {
            while (elevator_location != from) {
                elevator_location++;
                sleep();
                print();
            }
            elevator_door();

        }
    }

    public void movedown() {
        if (elevator_location != min && !emergency) {
            elevator_door();
            elevator_location--;
            print();
            sleep();
            elevator_door();
        }
    }

    public void movedown(int from ) {

        if (elevator_location != min && elevator_location != from && !emergency) {
            while (elevator_location != from) {
                elevator_location--;
                sleep();
                print();
            }
            elevator_door();

        }
    }

    public void moveto(int num) {

        if (elevator_location == num) {
            //elevator not move
        } else if (elevator_location < num && num <= max && !emergency) {
            elevator_door();
            System.out.println(name + ":" + "move to " + num);
            while (num != elevator_location) {
                moveup();
            }
            elevator_door();
        } else if (elevator_location > num && num >= min && !emergency) {
            elevator_door();
            System.out.println(name + ":" + "move to " + num);
            while (num != elevator_location) {
                movedown();
            }
            elevator_door();
        } else {
            if (num > max) {
                System.out.println("error cant go up more");
            } else {
                System.out.println("error cant down up more");
            }
        }

    }


}
