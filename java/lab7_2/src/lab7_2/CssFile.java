/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package lab7_2;

//import java.awt.Rectangle;


import javafx.application.Application;
import static javafx.application.Application.STYLESHEET_MODENA;
import javafx.scene.Scene;
import javafx.scene.effect.Reflection;
import javafx.scene.layout.StackPane;
import javafx.scene.paint.Color;
import javafx.scene.paint.CycleMethod;
import javafx.scene.paint.LinearGradient;
import javafx.scene.paint.Stop;
import javafx.scene.shape.Circle;
import javafx.scene.shape.Rectangle;
import javafx.scene.text.Font;
import javafx.scene.text.Text;
import javafx.stage.Stage;

public class CssFile extends Application {

    public static void main(String[] args) {
        Application.launch(args);
    }

    @Override
    public void start(Stage stage) throws Exception {
        Reflection reflection=new Reflection();
        Font font=new Font(STYLESHEET_MODENA, 20);
        reflection.setFraction(1.7);
        Text node1=new Text("I am really exciting");
        
        node1.setFont(font);
        //node1.setEffect(reflection);
        Circle node3=new Circle(10,10,100);
        node3.setFill(Color.LIGHTCYAN);
        Rectangle node2=new Rectangle(0,0,300,300);
        node2.setId("Ref");
        //LinearGradient l=new LinearGradient(0,0,300,300,false,CycleMethod.REFLECT,new Stop(0f,Color.PINK),new Stop(1.0f,Color.BLUEVIOLET));
        //node2.setFill(l);
        StackPane pane=new StackPane();
        pane.getChildren().addAll(node2,node3,node1);
        Scene scene=new Scene(pane,300,300);
        scene.getStylesheets().add(getClass().getResource("Reflection.css").toString());
        stage.setScene(scene);
        stage.show();
        
    }
}