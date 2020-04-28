/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package final_projectisa;


import gnu.io.CommPortIdentifier;
import gnu.io.SerialPort;
import gnu.io.SerialPortEvent;
import gnu.io.SerialPortEventListener;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.util.Enumeration;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;
import javafx.application.Application;
import javafx.application.Platform;
import javafx.beans.property.IntegerProperty;
import javafx.beans.property.SimpleIntegerProperty;
import javafx.beans.property.SimpleStringProperty;
import javafx.beans.property.StringProperty;
import javafx.beans.value.ChangeListener;
import javafx.beans.value.ObservableValue;
import javafx.concurrent.Task;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextArea;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.ColumnConstraints;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.Priority;
import javafx.scene.layout.RowConstraints;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;
import javafx.stage.StageStyle;

/**
 *
 * @author Mariam
 */


public class Calculator_Project extends Application implements SerialPortEventListener{

    /**
     * @param args the command line arguments
     */
    

    Integer i;
    Float data = 0f;
    int nflag = 0, firstDot = 1;
    char oper = '+';
    
    TextArea opField;
    public static Label resLabel;
    
    public static Button zero;
    public static Button one;
    public static Button two;
    public static Button three;
    public static Button four;
    public static Button five;
    public static Button six;
    public static Button seven;
    public static Button eight;
    public static Button nine;
    
    public static Button add;
    public static Button sub;
    public static Button div;
    public static Button mul;
    public static Button dot;
    public static Button equal;
    
    private BufferedReader input;
	/** The output stream to the port */
    private OutputStream output;
	/** Milliseconds to block while waiting for port open */
    private static final int TIME_OUT = 2000;
	/** Default bits per second for COM port. */
    private static final int DATA_RATE = 9600;

    String inputLine;
    
    /**
     *
     */
    public static StringProperty receivedNum = new SimpleStringProperty("0");
    
    SerialPort serialPort;
        /** The port we're normally going to use. */
	private static final String PORT_NAMES[] = {
			
                        
			"COM3", // Windows
	};
	/**
	* A BufferedReader which will be fed by a InputStreamReader 
	* converting the bytes into characters 
	* making the displayed results codepage independent
	*/
	
	public void initialize() {
               

		CommPortIdentifier portId = null;
		Enumeration portEnum = CommPortIdentifier.getPortIdentifiers();

		//First, Find an instance of serial port as set in PORT_NAMES.
		while (portEnum.hasMoreElements()) {
			CommPortIdentifier currPortId = (CommPortIdentifier) portEnum.nextElement();
			for (String portName : PORT_NAMES) {
				if (currPortId.getName().equals(portName)) {
					portId = currPortId;
					break;
				}
			}
		}
		if (portId == null) {
			System.out.println("Could not find COM port.");
			return;
		}

		try {
			// open serial port, and use class name for the appName.
			serialPort = (SerialPort) portId.open(this.getClass().getName(),
					TIME_OUT);

			// set port parameters
			serialPort.setSerialPortParams(DATA_RATE,
					SerialPort.DATABITS_8,
					SerialPort.STOPBITS_1,
					SerialPort.PARITY_NONE);

			// open the streams
			input = new BufferedReader(new InputStreamReader(serialPort.getInputStream()));
			output = serialPort.getOutputStream();

			// add event listeners
			serialPort.addEventListener(this);
			serialPort.notifyOnDataAvailable(true);
		} catch (Exception e) {
			System.err.println(e.toString());
		}
	}

	/**
	 * This should be called when you stop using the port.
	 * This will prevent port locking on platforms like Linux.
	 */
	public synchronized void close() {
		if (serialPort != null) {
			serialPort.removeEventListener();
			serialPort.close();
		}
	}

	/**
	 * Handle an event on the serial port. Read the data and print it.
	 */
	public synchronized void serialEvent(SerialPortEvent oEvent) {
		if (oEvent.getEventType() == SerialPortEvent.DATA_AVAILABLE) {
			try {
				inputLine=input.readLine();
				//System.out.println(inputLine);
			} catch (Exception e) {
				//System.err.println(e.toString());
			}
		}
		// Ignore all the other eventTypes, but you should consider the other ones.
	}
        
    @Override
    public void start(Stage s) throws Exception{
        
        /*TextField*/
        opField = new TextArea();
        opField.setId("textArea");
        opField.setDisable(true);
        opField.setMaxHeight(175);
        opField.setMinHeight(175);
        opField.setText("");
        
        /*Result Label*/
        resLabel = new Label("0");
        resLabel.setId("label");
        
        /*Result Pane*/
        StackPane resPane = new StackPane(opField, resLabel);
        resPane.setAlignment(Pos.BOTTOM_RIGHT);
        
        /*Operations*/
        /*Add*/
        add = new Button("+");
        add.setMaxSize(Double.MAX_VALUE, Double.MAX_VALUE);
        add.setId("opButton");
        add.setOnAction(new EventHandler<ActionEvent>() {

            @Override
            public void handle(ActionEvent t) {
                /*data += Float.parseFloat(opField.getText());
                opField.setText(data.toString()+"+");
                resLabel.setText(data.toString());*/
                
                opField.setText(opField.getText() + resLabel.getText()+"+");
                nflag = 0;
                increment();
                oper = '+';
                firstDot = 1;                
            }

            private void increment() {
                switch (oper){
                    case '+':
                        data += Float.parseFloat(resLabel.getText());
                        break;
                    case '-':
                        data -= Float.parseFloat(resLabel.getText());
                        break;
                    case '*':
                        data *= Float.parseFloat(resLabel.getText());
                        break;
                    case '/':
                        data /= Float.parseFloat(resLabel.getText());
                        break;
                }
                resLabel.setText(data.toString());
            }
        });
        
        
        /*Sub*/
        sub = new Button("-");
        sub.setMaxSize(Double.MAX_VALUE, Double.MAX_VALUE);
        sub.setId("opButton");
        sub.setOnAction(new EventHandler<ActionEvent>() {

            @Override
            public void handle(ActionEvent t) {
                opField.setText(opField.getText() + resLabel.getText()+"-");
                nflag = 0;
                decrement();
                oper = '-';
                firstDot = 1;
                
            }

            private void decrement() {
                switch (oper){
                    case '+':
                        data += Float.parseFloat(resLabel.getText());
                        break;
                    case '-':
                        data -= Float.parseFloat(resLabel.getText());
                        break;
                    case '*':
                        data *= Float.parseFloat(resLabel.getText());
                        break;
                    case '/':
                        data /= Float.parseFloat(resLabel.getText());
                        break;
                }
                resLabel.setText(data.toString());
            }
        });
        
        
        /*Div*/
        div = new Button("/");
        div.setMaxSize(Double.MAX_VALUE, Double.MAX_VALUE);
        div.setId("opButton");
        div.setOnAction(new EventHandler<ActionEvent>() {

            @Override
            public void handle(ActionEvent t) {
                /*data += Float.parseFloat(opField.getText());
                opField.setText(data.toString()+"+");
                resLabel.setText(data.toString());*/
                
                opField.setText(opField.getText() + resLabel.getText()+"/");
                nflag = 0;
                divide();
                oper = '/';
                firstDot = 1;
            }

            private void divide() {
                switch (oper){
                    case '+':
                        data += Float.parseFloat(resLabel.getText());
                        break;
                    case '-':
                        data -= Float.parseFloat(resLabel.getText());
                        break;
                    case '*':
                        data *= Float.parseFloat(resLabel.getText());
                        break;
                    case '/':
                        data /= Float.parseFloat(resLabel.getText());
                        break;
                }
                resLabel.setText(data.toString());
            }
        });
        
        /*Mul*/
        mul = new Button("*");
        mul.setMaxSize(Double.MAX_VALUE, Double.MAX_VALUE);
        mul.setId("opButton");
        mul.setOnAction(new EventHandler<ActionEvent>() {

            @Override
            public void handle(ActionEvent t) {
                opField.setText(opField.getText() + resLabel.getText()+"*");
                nflag = 0;
                multiply();
                oper = '*';
                firstDot = 1;
            }

            private void multiply() {
                switch (oper){
                    case '+':
                        data += Float.parseFloat(resLabel.getText());
                        break;
                    case '-':
                        data -= Float.parseFloat(resLabel.getText());
                        break;
                    case '*':
                        data *= Float.parseFloat(resLabel.getText());
                        break;
                    case '/':
                        data /= Float.parseFloat(resLabel.getText());
                        break;
                }
                resLabel.setText(data.toString());
            }
        });
        
        
        /*Floating Point*/
        dot = new Button(".");
        dot.setMaxSize(Double.MAX_VALUE, Double.MAX_VALUE);
        dot.setId("opButton");
        dot.setOnAction(new EventHandler<ActionEvent>() {

            @Override
            public void handle(ActionEvent t) {
                if (firstDot == 1)
                {
                    if(nflag == 0)
                    {
                        resLabel.setText("0");
                    }
                    nflag = 1;
                    resLabel.setText(resLabel.getText() + ".");
                    firstDot=0;
                }
            }
        });
        
        
        /*Assignment*/
        equal = new Button("=");
        equal.setMaxSize(Double.MAX_VALUE, Double.MAX_VALUE);
        equal.setId("opButton");
        equal.setOnAction(new EventHandler<ActionEvent>() {

            @Override
            public void handle(ActionEvent t) {
                nflag = 0;
                opField.setText("");
                equal();
                data = 0f;
            }

            private void equal() {
                switch (oper){
                    case '+':
                        data += Float.parseFloat(resLabel.getText());
                        break;
                    case '-':
                        data -= Float.parseFloat(resLabel.getText());
                        break;
                    case '*':
                        data *= Float.parseFloat(resLabel.getText());
                        break;
                    case '/':
                        data /= Float.parseFloat(resLabel.getText());
                        break;
                }
                resLabel.setText(data.toString());
                oper = '+';
            }
        });
        
        
        /*Main Buttons Grid*/
        GridPane buttonsPane = new GridPane();
        
        for (int col = 0 ; col < 4 ; col++ ){
            ColumnConstraints colConst = new ColumnConstraints();
            colConst.setHgrow(Priority.ALWAYS) ;
            colConst.setFillWidth(true);
            buttonsPane.getColumnConstraints().add(colConst); 
        }
        
        for (int row = 0 ; row < 4 ; row++ ){
            RowConstraints rowConst = new RowConstraints();
            rowConst.setVgrow(Priority.ALWAYS) ;
            rowConst.setFillHeight(true);
            buttonsPane.getRowConstraints().add(rowConst); 
        }
        
        
        /*Numbers Buttons*/
        zero = new Button("0");
        zero.setMaxSize(Double.MAX_VALUE, Double.MAX_VALUE);
        zero.setId("numButton");
        zero.setOnAction(new EventHandler<ActionEvent>() {

                @Override
                public void handle(ActionEvent t) {
                    if(nflag == 0)
                    {
                        resLabel.setText("");
                    }
                    nflag = 1;
                    resLabel.setText(resLabel.getText()+"0");
                    zero.setStyle("-fx-background-color: #229f9f");
                }
            }
            );
        
        
        one = new Button("1");
        one.setMaxSize(Double.MAX_VALUE, Double.MAX_VALUE);
        one.setId("numButton");
        one.setOnAction(new EventHandler<ActionEvent>() {

                @Override
                public void handle(ActionEvent t) {
                    //opField.setText(opField.getText()+"1");
                    if(nflag == 0)
                    {
                        resLabel.setText("");
                    }
                    nflag = 1;
                    resLabel.setText(resLabel.getText()+"1");
                    one.setStyle("-fx-background-color: #229f9f");
                   
                }
            }
            );

        two = new Button("2");
        two.setMaxSize(Double.MAX_VALUE, Double.MAX_VALUE);
        two.setId("numButton");
        two.setOnAction(new EventHandler<ActionEvent>() {

                @Override
                public void handle(ActionEvent t) {
                    
                    if(nflag == 0)
                    {
                        resLabel.setText("");
                    }
                    nflag = 1;
                    //opField.setText(opField.getText()+"2");
                    resLabel.setText(resLabel.getText()+"2");
                    two.setStyle("-fx-background-color: #229f9f");
                    
                }
            }
            );
        
        three = new Button("3");
        three.setMaxSize(Double.MAX_VALUE, Double.MAX_VALUE);
        three.setId("numButton");
        three.setOnAction(new EventHandler<ActionEvent>() {

                @Override
                public void handle(ActionEvent t) {
                    if(nflag == 0)
                    {
                        resLabel.setText("");
                    }
                    nflag = 1;
                    //opField.setText(opField.getText()+"3");
                    resLabel.setText(resLabel.getText()+"3");
                    three.setStyle("-fx-background-color: #229f9f");
                }
            }
            );
        
        four = new Button("4");
        four.setMaxSize(Double.MAX_VALUE, Double.MAX_VALUE);
        four.setId("numButton");
        four.setOnAction(new EventHandler<ActionEvent>() {

                @Override
                public void handle(ActionEvent t) {
                    if(nflag == 0)
                    {
                        resLabel.setText("");
                    }
                    nflag = 1;
                    //opField.setText(opField.getText()+"4");
                    resLabel.setText(resLabel.getText()+"4");
                    four.setStyle("-fx-background-color: #229f9f");
                }
            }
            );
        
        five = new Button("5");
        five.setMaxSize(Double.MAX_VALUE, Double.MAX_VALUE);
        five.setId("numButton");
        five.setOnAction(new EventHandler<ActionEvent>() {

                @Override
                public void handle(ActionEvent t) {
                    if(nflag == 0)
                    {
                        resLabel.setText("");
                    }
                    nflag = 1;
                    //opField.setText(opField.getText()+"5");
                    resLabel.setText(resLabel.getText()+"5");
                    five.setStyle("-fx-background-color: #229f9f");
                }
            }
            );
        
        six = new Button("6");
        six.setMaxSize(Double.MAX_VALUE, Double.MAX_VALUE);
        six.setId("numButton");
        six.setOnAction(new EventHandler<ActionEvent>() {

                @Override
                public void handle(ActionEvent t) {
                    if(nflag == 0)
                    {
                        resLabel.setText("");
                    }
                    nflag = 1;
                    //opField.setText(opField.getText()+"6");
                    resLabel.setText(resLabel.getText()+"6");
                    six.setStyle("-fx-background-color: #229f9f");
                }
            }
            );
        
        seven = new Button("7");
        seven.setMaxSize(Double.MAX_VALUE, Double.MAX_VALUE);
        seven.setId("numButton");
        seven.setOnAction(new EventHandler<ActionEvent>() {

                @Override
                public void handle(ActionEvent t) {
                    if(nflag == 0)
                    {
                        resLabel.setText("");
                    }
                    nflag = 1;
                    //opField.setText(opField.getText()+"7");
                    resLabel.setText(resLabel.getText()+"7");
                    seven.setStyle("-fx-background-color: #229f9f");
                }
            }
            );
        
        eight = new Button("8");
        eight.setMaxSize(Double.MAX_VALUE, Double.MAX_VALUE);
        eight.setId("numButton");
        eight.setOnAction(new EventHandler<ActionEvent>() {

                @Override
                public void handle(ActionEvent t) {
                    if(nflag == 0)
                    {
                        resLabel.setText("");
                    }
                    nflag = 1;
                    //opField.setText(opField.getText()+"8");
                    resLabel.setText(resLabel.getText()+"8");
                    eight.setStyle("-fx-background-color: #229f9f");
                }
            }
            );
        
        nine = new Button("9");
        nine.setMaxSize(Double.MAX_VALUE, Double.MAX_VALUE);
        nine.setId("numButton");
        nine.setOnAction(new EventHandler<ActionEvent>() {

                @Override
                public void handle(ActionEvent t) {
                    if(nflag == 0)
                    {
                        resLabel.setText("");
                    }
                    nflag = 1;
                    //opField.setText(opField.getText()+"9");
                    resLabel.setText(resLabel.getText()+"9");
                    nine.setStyle("-fx-background-color: #229f9f");
                }
            }
            );
        
        buttonsPane.addRow(0, seven, eight, nine, add);
        buttonsPane.addRow(1, four, five, six, sub);
        buttonsPane.addRow(2, one, two, three, div);
        buttonsPane.addRow(3, dot, zero, equal, mul);
        
       
        /*CopyRights Label*/
        Label copyRights = new Label("All rights reserved @ Team Bta3");
        
        /*Pane*/
        BorderPane mainPane = new BorderPane();
        mainPane.setTop(resPane);
        mainPane.setCenter(buttonsPane);
        mainPane.setBottom(copyRights);
        
        /*Scene*/
        Scene mainScene = new Scene(mainPane, 550, 750);
        mainScene.getStylesheets().add(getClass().getResource("calcStyle.css").toString());
        
        
        /*Stage*/
        s.setTitle("SuperCalc");
        s.setScene(mainScene);
        s.initStyle(StageStyle.UTILITY);
        s.show();
        
        /*IntegerProperty invokes a handler when value is changed (through console/ port)*/
        final ChangeListener changeListener = new ChangeListener() 
        {
            @Override
            public void changed(ObservableValue observable, Object oldValue, Object newValue) {
                setLabelText();
            }
        };
        
        receivedNum.addListener(changeListener);
        
        Thread get_Thread = new Thread(new Runnable()
        {
            public void run()
            {
                while(true)
                {
                    Integer inputt = 0;
                    try {
                        inputLine=input.readLine();
                        receivedNum.set(inputLine);
                        
                    } catch (IOException ex) {
                        Logger.getLogger(Calculator_Project.class.getName()).log(Level.SEVERE, null, ex);
                    }
	            //System.out.println(inputLine);
                    //Scanner in = new Scanner(System.in);
                    //System.out.println("Enter num: ");
                    //inputt = in.nextInt();
                    //receivedNum.set(inputt);
                }
            }
        });
        get_Thread.start();
        
    }
    
    public void setLabelText(){
        Task<Void> task = new Task<Void>() {
                    @Override
                    protected Void call() {
                        Platform.runLater(new Runnable() {

                            @Override
                            public void run() {
                                Calculator_Project.resLabel.setText(resLabel.getText()+receivedNum.getValue().toString());
                                switch(receivedNum.getValue()){
                                    case "0":
                                        zero.setStyle("-fx-background-color: #229f9f");
                                        break;
                                    case "1":
                                        one.setStyle("-fx-background-color: #229f9f");
                                        break;
                                    case "2":
                                        two.setStyle("-fx-background-color: #229f9f");
                                        break;
                                    case "3":
                                        three.setStyle("-fx-background-color: #229f9f");
                                        break;
                                    case "4":
                                        four.setStyle("-fx-background-color: #229f9f");
                                        break;
                                    case "5":
                                        five.setStyle("-fx-background-color: #229f9f");
                                        break;
                                    case "6":
                                        six.setStyle("-fx-background-color: #229f9f");
                                        break;
                                    case "7":
                                        seven.setStyle("-fx-background-color: #229f9f");
                                        break;
                                    case "8":
                                        eight.setStyle("-fx-background-color: #229f9f");
                                        break;
                                    case "9":
                                        nine.setStyle("-fx-background-color: #229f9f");
                                }
                            }

                        });
                        return null;
                    }
                };
                
        Thread style_Thread = new Thread(task);
        style_Thread.setDaemon(true);
        style_Thread.start();
    }
    public static void main(String[] args) {
        // TODO code application logic here
        
        Application.launch(args);
        
                
    }
    
}

