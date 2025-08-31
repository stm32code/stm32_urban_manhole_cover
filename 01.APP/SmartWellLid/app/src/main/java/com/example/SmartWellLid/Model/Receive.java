package com.example.SmartWellLid.Model;

public class Receive {
    String temp = null;
    String humi = null;
    String eat = null;
    String food = null;
    String food_v = null;
    String door = null;

    public String getMq4() {
        return mq4;
    }

    String mq4 = null;
    String water = null;
    String time = null;

    public String getTime() {
        return time;
    }

    public String getTime_s() {
        return time_s;
    }

    String time_s = null;
    @Override
    public String toString() {
        return "Receive{" +
                "temp='" + temp + '\'' +
                ", humi='" + humi + '\'' +
                ", eat='" + eat + '\'' +
                ", food='" + food + '\'' +
                ", food_v='" + food_v + '\'' +
                ", door='" + door + '\'' +
                ", water='" + water + '\'' +
                ", time='" + time + '\'' +
                ", time_s='" + time_s + '\'' +
                '}';
    }

    public String getTemp() {
        return temp;
    }

    public void setTemp(String temp) {
        this.temp = temp;
    }

    public String getHumi() {
        return humi;
    }

    public void setHumi(String humi) {
        this.humi = humi;
    }

    public String getEat() {
        return eat;
    }

    public void setEat(String eat) {
        this.eat = eat;
    }

    public String getFood() {
        return food;
    }

    public void setFood(String food) {
        this.food = food;
    }

    public String getFood_v() {
        return food_v;
    }

    public void setFood_v(String food_v) {
        this.food_v = food_v;
    }

    public String getDoor() {
        return door;
    }

    public void setDoor(String door) {
        this.door = door;
    }

    public String getWater() {
        return water;
    }

    public void setWater(String water) {
        this.water = water;
    }
}
