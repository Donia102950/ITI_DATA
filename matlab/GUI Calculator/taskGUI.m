function varargout = taskGUI(varargin)
% TASKGUI MATLAB code for taskGUI.fig
%      TASKGUI, by itself, creates a new TASKGUI or raises the existing
%      singleton*.
%
%      H = TASKGUI returns the handle to a new TASKGUI or the handle to
%      the existing singleton*.
%
%      TASKGUI('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in TASKGUI.M with the given input arguments.
%
%      TASKGUI('Property','Value',...) creates a new TASKGUI or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before taskGUI_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to taskGUI_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help taskGUI

% Last Modified by GUIDE v2.5 02-Jan-2020 15:17:53

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @taskGUI_OpeningFcn, ...
                   'gui_OutputFcn',  @taskGUI_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before taskGUI is made visible.
function taskGUI_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to taskGUI (see VARARGIN)

% Choose default command line output for taskGUI
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes taskGUI wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = taskGUI_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on button press in result.
function result_Callback(hObject, eventdata, handles)
% hObject    handle to result (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
x=get(handles.check,'String');
switch(x)
    case '+'
        set(handles.op,'String',x);
        number1=get(handles.num1,'String');
        number2=get(handles.num2,'String');
        z=str2num(number1)+str2num(number2);
        if (z>100)
            set(handles.res,'BackGroundColor','green');
            matlabImage = imread('happy.jpg');
            image(matlabImage)
            axis off
            axis image
        else
            set(handles.res,'BackGroundColor','red');
            matlabImage = imread('sad.jpg');
            image(matlabImage)
            axis off
            axis image
        end
        set(handles.res,'String',z);;
    case '-'
        set(handles.op,'String',x);
        number1=get(handles.num1,'String');
        number2=get(handles.num2,'String');
        z=str2num(number1)-str2num(number2);
         if (z>100)
            set(handles.res,'BackGroundColor','green');
            matlabImage = imread('happy.jpg');
            image(matlabImage)
            axis off
            axis image
        else
            set(handles.res,'BackGroundColor','red');
            matlabImage = imread('sad.jpg');
            image(matlabImage)
            axis off
            axis image
        end
        set(handles.res,'String',z);;
    case '*'
        set(handles.op,'String',x);
        number1=get(handles.num1,'String');
        number2=get(handles.num2,'String');
        z=str2num(number1)*str2num(number2);
         if (z>100)
            set(handles.res,'BackGroundColor','green');
            matlabImage = imread('happy.jpg');
            image(matlabImage)
            axis off
            axis image
        else
            set(handles.res,'BackGroundColor','red');
            matlabImage = imread('sad.jpg');
            image(matlabImage)
            axis off
            axis image
        end
        set(handles.res,'String',z);;
    case '/'
        set(handles.op,'String',x);
        number1=get(handles.num1,'String');
        number2=get(handles.num2,'String');
        z=str2num(number1)/str2num(number2);
          if (z>100)
            set(handles.res,'BackGroundColor','green');
            matlabImage = imread('happy.jpg');
            image(matlabImage)
            axis off
            axis image
        else
            set(handles.res,'BackGroundColor','red');
            matlabImage = imread('sad.jpg');
            image(matlabImage)
            axis off
            axis image
        end
        set(handles.res,'String',z);;
end
        


%set(handles.op,'String',x);



function num1_Callback(hObject, eventdata, handles)
% hObject    handle to num1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of num1 as text
%        str2double(get(hObject,'String')) returns contents of num1 as a double


% --- Executes during object creation, after setting all properties.
function num1_CreateFcn(hObject, eventdata, handles)
% hObject    handle to num1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function num2_Callback(hObject, eventdata, handles)
% hObject    handle to num2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of num2 as text
%        str2double(get(hObject,'String')) returns contents of num2 as a double


% --- Executes during object creation, after setting all properties.
function num2_CreateFcn(hObject, eventdata, handles)
% hObject    handle to num2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function res_Callback(hObject, eventdata, handles)
% hObject    handle to res (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of res as text
%        str2double(get(hObject,'String')) returns contents of res as a double


% --- Executes during object creation, after setting all properties.
function res_CreateFcn(hObject, eventdata, handles)
% hObject    handle to res (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function check_Callback(hObject, eventdata, handles)
% hObject    handle to check (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of check as text
%        str2double(get(hObject,'String')) returns contents of check as a double


% --- Executes during object creation, after setting all properties.
function check_CreateFcn(hObject, eventdata, handles)
% hObject    handle to check (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function op_Callback(hObject, eventdata, handles)
% hObject    handle to op (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of op as text
%        str2double(get(hObject,'String')) returns contents of op as a double


% --- Executes during object creation, after setting all properties.
function op_CreateFcn(hObject, eventdata, handles)
% hObject    handle to op (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function edit6_Callback(hObject, eventdata, handles)
% hObject    handle to edit6 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit6 as text
%        str2double(get(hObject,'String')) returns contents of edit6 as a double


% --- Executes during object creation, after setting all properties.
function edit6_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit6 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end
