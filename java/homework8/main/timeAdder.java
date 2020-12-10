package main;

public class timeAdder {
    int seconds;
    int minutes;
    int hours;
    int day;
    public timeAdder(int value1, String label_1, int value2, String label_2) {
        if (value1 <= -1 || value2 <= -1) {
            throw new IllegalArgumentException("invalid argument");
        }
        add(value1, label_1);
        add(value2, label_2);
    }

    public void print() {
        System.out.println("days " + day);
        System.out.println("hours " + hours);
        System.out.println("minutes " + minutes);
        System.out.println("seconds " + seconds + "\n");

    }

    private void add(int value, String label) {
        switch (label) {
            case "second", "seconds" -> {
                minutes += (value / 60);
                seconds += (value % 60);
            }
            case "minute", "minutes" -> {
                hours += (value / 60);
                minutes += (value % 60);
            }
            case "hour", "hours" -> {
                day += value/24;
                hours += value%24;
            }
            case "day","days" -> day += value;
            default -> throw new IllegalArgumentException(String.format("%s is not valid argument", label));
        }

    }
}
