package main;

public class mainj {

    public static void main(String[] args) {
        //how to use program
        //
        elevator A = new elevator(-1,9,"A");// <- elevator A (Goes to all floors except the penthouse (floor 10))
        elevator B = new elevator(0,10,"B");// <- elevator B (Goes all the way up (including 10) but does not go to the basement (-1))
        //Floors 1 - 9 contain two buttons to call the elevators: An "up" button and a "down" button.
        //Floor 10 contains only a "down" button
        //Floor -1 contains only an "up" button.
        A.moveto(5);// <- user want to go to floor 5 by press button 5
        A.movedown(4);// <- call elevator from floor 4
        B.moveto(10);
        B.movedown(1);// <- call elevator from floor 1
        A.emergency_button();// <- the elevators go to their nearest floor and open their doors.
        A.reset();// <- The doors remain open until a reset button is pushed inside of the elevator.


    }

}

