package homework;

import javax.swing.*;
import java.awt.*;

public class tictactoe {
    boolean[] turn_set = {true, true, true, true, true, true, true, true, true, true};
    char[] board = {' ', ' ', ' ',
            ' ', ' ', ' ',
            ' ', ' ', ' ',};
    char player_x = 'X', player_y = 'O';
    String Win_Message = "player %S win the Game!!";
    JButton button1 = new JButton();
    JButton button2 = new JButton();
    JButton button3 = new JButton();
    JButton button4 = new JButton();
    JButton button5 = new JButton();
    JButton button6 = new JButton();
    JButton button7 = new JButton();
    JButton button8 = new JButton();
    JButton button9 = new JButton();

    tictactoe() {
        JFrame frame = new JFrame("TICTACTOE MADE BY RIFQI NUGRAHA");
        JPanel panel = new JPanel();
        panel.setLayout(null);
        int []size_bottom = {50,50};
        //

        button1.setSize(size_bottom[0], size_bottom[1]);
        button1.addActionListener(e -> {
            if (turn_set[1]) button1.setText(turn(1));
        });

        button2.setSize(size_bottom[0], size_bottom[1]);
        button2.addActionListener(e -> {
            if (turn_set[2]) button2.setText(turn(2));
        });

        button3.setSize(size_bottom[0], size_bottom[1]);
        button3.addActionListener(e -> {
            if (turn_set[3]) button3.setText(turn(3));
        });

        button4.setSize(size_bottom[0], size_bottom[1]);
        button4.addActionListener(e -> {
            if (turn_set[4]) button4.setText(turn(4));
        });

        button5.setSize(size_bottom[0], size_bottom[1]);
        button5.addActionListener(e -> {
            if (turn_set[5]) button5.setText(turn(5));
        });

        button6.setSize(size_bottom[0], size_bottom[1]);
        button6.addActionListener(e -> {
            if (turn_set[6]) button6.setText(turn(6));
        });

        button7.setSize(size_bottom[0], size_bottom[1]);
        button7.addActionListener(e -> {
            if (turn_set[7]) button7.setText(turn(7));
        });

        button8.setSize(size_bottom[0], size_bottom[1]);
        button8.addActionListener(e -> {
            if (turn_set[8]) button8.setText(turn(8));
        });
        button9.setSize(size_bottom[0], size_bottom[1]);
        button9.addActionListener(e -> {
            if (turn_set[9]) button9.setText(turn(9));
        });


        panel.setLayout(new GridLayout(3, 4));
        panel.add(button1);
        panel.add(button2);
        panel.add(button3);
        panel.add(button4);
        panel.add(button5);
        panel.add(button6);
        panel.add(button7);
        panel.add(button8);
        panel.add(button9);
        //
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.pack();
        frame.setSize(500, 300);
        frame.setLocationRelativeTo(null);
        frame.setContentPane(panel);
        frame.setVisible(true);
    }

    public static void main(String[] args) {
        new tictactoe();
    }

    public char winner(char player, int num1, int num2, int num3) {

        if (board[num1] == player && board[num2] == player && board[num3] == player) {
            return player;
        }
        return ' ';
    }

    //Cats game!
    public boolean Catsgame() {
        return board[0] != ' ' && board[1] != ' ' && board[2] != ' ' &&
                board[3] != ' ' && board[4] != ' ' && board[5] != ' ' &&
                board[6] != ' ' && board[7] != ' ' && board[8] != ' ';
    }

    public boolean game_over() {
        if (winner(player_x, 0, 1, 2) == player_x
                || winner(player_x, 3, 4, 5) == player_x
                || winner(player_x, 6, 7, 8) == player_x
                || winner(player_x, 0, 3, 6) == player_x
                || winner(player_x, 1, 4, 7) == player_x
                || winner(player_x, 2, 5, 8) == player_x
                || winner(player_x, 0, 4, 8) == player_x
                || winner(player_x, 6, 4, 2) == player_x
        ) {
            return true;
        } else if (Catsgame()) {
            return true;
        } else return winner(player_y, 0, 1, 2) == player_y
                || winner(player_y, 3, 4, 5) == player_y
                || winner(player_y, 6, 7, 8) == player_y
                || winner(player_y, 0, 3, 6) == player_y
                || winner(player_y, 1, 4, 7) == player_y
                || winner(player_y, 2, 5, 8) == player_y
                || winner(player_y, 0, 4, 8) == player_y
                || winner(player_y, 6, 4, 2) == player_y;
    }

    public void reset() {
        try {
            for (int i = 0; i <= 10; i++) {
                board[i] = ' ';
                turn_set[i] = true;
            }
        } catch (Exception e) {
            //empty code
        } finally {
            button1.setText(" ");
            button2.setText(" ");
            button3.setText(" ");
            button4.setText(" ");
            button5.setText(" ");
            button6.setText(" ");
            button7.setText(" ");
            button8.setText(" ");
            button9.setText(" ");
        }


    }

    public String turn(int i) {
        String cat = "catsgame!!";
        turn_set[i] = false;
        turn_set[0] = !turn_set[0];
        if (!turn_set[0]) {
            board[i - 1] = player_x;

            if (game_over()) {
                if (Catsgame()) {
                    JOptionPane.showMessageDialog(null, cat);
                } else {
                    JOptionPane.showMessageDialog(null, String.format(Win_Message, player_x));
                }
                reset();
                return " ";
            }
            return "X";
        } else {
            board[i - 1] = player_y;
            if (game_over()) {
                if (Catsgame()) {
                    JOptionPane.showMessageDialog(null, cat);
                } else {
                    JOptionPane.showMessageDialog(null, String.format(Win_Message, player_y));
                }
                reset();
                return " ";
            } else
                return "O";
        }

    }
}
