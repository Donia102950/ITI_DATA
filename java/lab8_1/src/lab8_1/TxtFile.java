/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab8_1;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;
import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.control.Menu;
import javafx.scene.control.MenuBar;
import javafx.scene.control.MenuItem;
import javafx.scene.control.Separator;
import javafx.scene.control.SeparatorMenuItem;
import javafx.scene.control.TextArea;
import javafx.scene.layout.BorderPane;
import javafx.stage.FileChooser;
import javafx.stage.Stage;
import javax.swing.JFileChooser;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;

public class TxtFile extends Application {

    public static void main(String[] args) {

        Application.launch(args);

    }

    public void start(Stage stage) throws Exception {
        MenuBar bar = new MenuBar();
        Menu file = new Menu("File");
        Menu edit = new Menu("Edit");
        Menu help = new Menu("Help");
        TextArea notepad = new TextArea();
        FileChooser fileSave;
        File fileToSave;
        FileChooser ch = new FileChooser();

        MenuItem item1 = new MenuItem("new");
        MenuItem item2 = new MenuItem("open");
        MenuItem item3 = new MenuItem("save");
        MenuItem item4 = new MenuItem("Exit");
        MenuItem item5 = new MenuItem("Undo");
        MenuItem item6 = new MenuItem("Cut");
        MenuItem item7 = new MenuItem("Copy");
        MenuItem item8 = new MenuItem("Paste");
        MenuItem item9 = new MenuItem("Delete");
        MenuItem item10 = new MenuItem("Delete all");

        file.getItems().addAll(item1, item2, item3, new SeparatorMenuItem(), item4);
        edit.getItems().addAll(item5, new SeparatorMenuItem(), item6, item7, item8, item9, item10);

        bar.getMenus().addAll(file, edit, help);

        BorderPane pane = new BorderPane();
        pane.setTop(bar);
        pane.setCenter(notepad);
        Scene scene = new Scene(pane, 300, 400);

        stage.setScene(scene);
        stage.show();

        item1.setOnAction(new EventHandler<ActionEvent>() {
            public void handle(ActionEvent e) {
                notepad.setText("");
            }
        });
        item2.setOnAction(new EventHandler<ActionEvent>() {
            public void handle(ActionEvent e) {
                ch.setTitle("Open File");
                File file = ch.showOpenDialog(new Stage());

                try {
                    BufferedReader br = new BufferedReader(new FileReader(file));
                    String line;

                    while ((line = br.readLine()) != null) {
                        notepad.appendText(line);
                        br.close();
                    }
                } catch (IOException ex) {
                    System.out.println("We cannot able to open this file");
                    ex.printStackTrace();
                }

            }
        });

        item3.setOnAction(new EventHandler<ActionEvent>() {

            @Override
            public void handle(ActionEvent t) {
                String text;
                ch.setTitle("Save File");
                File file2 = new File("K:\\java programs\\tst.txt");
                try {
                    BufferedWriter wr = new BufferedWriter(new FileWriter(file2));
                    text = notepad.getText();
                    wr.write(text);
                    wr.close();
                } catch (IOException ex) {
                    Logger.getLogger(TxtFile.class.getName()).log(Level.SEVERE, null, ex);
                }

            }

        });

        item4.setOnAction(new EventHandler<ActionEvent>() {

            @Override
            public void handle(ActionEvent t) {
               stage.close();
            }

        });
        
           item5.setOnAction(new EventHandler<ActionEvent>() {

            @Override
            public void handle(ActionEvent t) {
               notepad.undo();
            }

        });
           
            item6.setOnAction(new EventHandler<ActionEvent>() {

            @Override
            public void handle(ActionEvent t) {
               notepad.cut();
            }

        });
            
                     item6.setOnAction(new EventHandler<ActionEvent>() {

            @Override
            public void handle(ActionEvent t) {
               notepad.cut();
            }

        });
                     
                          
             item7.setOnAction(new EventHandler<ActionEvent>() {

            @Override
            public void handle(ActionEvent t) {
               String note=notepad.getText();
            }

        });
             
                    item8.setOnAction(new EventHandler<ActionEvent>() {

            @Override
            public void handle(ActionEvent t) {
                String s;
               notepad.paste();
            }

        });
                    
                    item9.setOnAction(new EventHandler<ActionEvent>() {

            @Override
            public void handle(ActionEvent t) {
                String s;
               notepad.deletePreviousChar();
            }

        });
                    
                    item10.setOnAction(new EventHandler<ActionEvent>() {

            @Override
            public void handle(ActionEvent t) {
                String s;
               notepad.clear();
            }

        });

    }

}
