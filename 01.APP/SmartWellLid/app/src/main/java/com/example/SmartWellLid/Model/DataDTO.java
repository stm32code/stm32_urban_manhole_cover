package com.example.SmartWellLid.Model;

public class DataDTO {
    private Float food_v;
    private Integer door;

    public void setTime(Integer time) {
        this.time = time;
    }

    public void setTime_s(Integer time_s) {
        this.time_s = time_s;
    }

    private Integer time;
    private Integer time_s;
    @Override
    public String toString() {
        return "DataDTO{" +
                "food_v=" + food_v +
                ", door=" + door +
                ", time=" + time +
                ", time_s=" + time_s +

                '}';
    }

    public Float getFood_v() {
        return food_v;
    }

    public void setFood_v(Float food_v) {
        this.food_v = food_v;
    }

    public Integer getDoor() {
        return door;
    }

    public void setDoor(Integer door) {
        this.door = door;
    }
}
