
function varargout = untitled(varargin)
% UNTITLED MATLAB code for untitled.fig
%      UNTITLED, by itself, creates a new UNTITLED or raises the existing
%      singleton*.
%
%      H = UNTITLED returns the handle to a new UNTITLED or the handle to
%      the existing singleton*.
%
%      UNTITLED('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in UNTITLED.M with the given input arguments.
%
%      UNTITLED('Property','Value',...) creates a new UNTITLED or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before untitled_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to untitled_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help untitled

% Last Modified by GUIDE v2.5 10-May-2018 21:42:50

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @untitled_OpeningFcn, ...
                   'gui_OutputFcn',  @untitled_OutputFcn, ...
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

% --- Executes just before untitled is made visible.
function untitled_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to untitled (see VARARGIN)

% Choose default command line output for untitled
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes untitled wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = untitled_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;
function buttonStart_Callback(hObject, eventdata, handles)
% hObject    handle to buttonStart (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

    %%Main mat%%
    global mat;
    mat=[0 0 0 0;0 0 0 0;0 0 0 0;0 0 0 0];
    %%Main length%%
    global length;
    length=4;
    %%UI settings%%
    axis equal
    axis square
    axis off
    hold on

    %%Return to 0%%
    for i=1:length
        for j=1:length
            mat(i,j)=0;
        end
    end 
    %%Give a initial data%%
    for i=1:20
        ranX=fix(4*rand())+1;
        ranY=fix(4*rand())+1;
        mat(ranX,ranY)=2;
    end
    %%Show in UI%%
    for i=1:length
        for j=1:length
            patch([i,i,i+1,i+1],[j,j+1,j+1,j],[0.3,0.6,mod(mat(i,j),48)/48])
            text(i+0.5,j+0.5,int2str(mat(i,j)),'color',[1,1,1],'fontsize',20,'HorizontalAlignment','center');
        end
    end
function buttonUp_Callback(hObject, eventdata, handles)
% hObject    handle to buttonUp (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
upMove();
upAdd();
upMove();
push(1);
update();
function buttonDown_Callback(hObject, eventdata, handles)
% hObject    handle to buttonDown (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
downMove();
downAdd();
downMove();
push(2);
update();
function buttonLeft_Callback(hObject, eventdata, handles)
% hObject    handle to buttonLeft (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
leftMove();
leftAdd();
leftMove();
push(3);
update();
function buttonRight_Callback(hObject, eventdata, handles)
% hObject    handle to buttonRight (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
rightMove();
rightAdd();
rightMove();
push(4);
update();
function Untitled_2_Callback(hObject, eventdata, handles)
% hObject    handle to Untitled_2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
msgbox({'点击方向键推动元素','尽可能获得最高分！'},'Help','warn');
function Untitled_3_Callback(hObject, eventdata, handles)
% hObject    handle to Untitled_2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
msgbox({'作者：卢立强[71117417]'},'Help','warn');
function update()
    %global
    global mat
    global length

        for i=1:length
            for j=1:length
                patch([i,i,i+1,i+1],[j,j+1,j+1,j],[0.3,0.6,mod(mat(i,j),48)/48])
                text(i+0.5,j+0.5,int2str(mat(i,j)),'color',[1,1,1],'fontsize',20,'HorizontalAlignment','center');
            end
        end
function left()
    leftMove();
    leftAdd();
    leftMove();
    update();
function leftMove()
    %global
    global mat
    global length

    for i=1:length
        for j=1:length
            if mat(j,i)==0
                for k=j+1:length
                    if mat(k,i)~=0
                        mat(j,i)=mat(k,i);
                        mat(k,i)=0;
                        break;
                    end
                end
            end
        end
    end
function leftAdd()
    %global
    global mat
    global length
    
    for i=1:length
        for j=1:length
            if mat(j,i)==0
                continue;
            end
            if j<length
                if mat(j,i)==mat(j+1,i)
                    mat(j,i)=2.*mat(j,i);
                    mat(j+1,i)=0;
                end
            end
        end
    end
function right()
    rightMove();
    rightAdd();
    rightMove();
    update();
function rightMove()
    %global
    global mat
    global length

    for i=length:-1:1
        for j=length:-1:1
            if mat(j,i)==0
                for k=j-1:-1:1
                    if mat(k,i)~=0
                        mat(j,i)=mat(k,i);
                        mat(k,i)=0;
                        break;
                    end
                end
            end
        end
    end
function rightAdd()
    %global
    global mat
    global length
    
    for i=1:length
        for j=1:length
            if mat(j,i)==0
                continue;
            end
            if j<length
                if mat(j,i)==mat(j+1,i)
                    mat(j,i)=2.*mat(j,i);
                    mat(j+1,i)=0;
                end
            end
        end
    end
function down()
    downMove();
    downAdd();
    downMove();
    update();
function downMove()
    %global
    global mat
    global length

    for i=1:length
        for j=1:length
            if mat(i,j)==0
                for k=j+1:length
                    if mat(i,k)~=0
                        mat(i,j)=mat(i,k);
                        mat(i,k)=0;
                        break;
                    end
                end
            end
        end
    end
function downAdd()
    %global
    global mat
    global length
    
    for i=1:length
        for j=1:length
            if mat(i,j)==0
                continue;
            end
            if j<length
                if mat(i,j)==mat(i,j+1)
                    mat(i,j)=2.*mat(i,j);
                    mat(i,j+1)=0;
                end
            end
        end
    end
function up()
    upMove();
    upAdd();
    upMove();
    update();
function upMove()
    %global
    global mat
    global length

    for i=length:-1:1
        for j=length:-1:1
            if mat(i,j)==0
                for k=j-1:-1:1
                    if mat(i,k)~=0
                        mat(i,j)=mat(i,k);
                        mat(i,k)=0;
                        break;
                    end
                end
            end
        end
    end
function upAdd()
    %global
    global mat
    global length
    
    for i=1:length
        for j=1:length
            if mat(i,j)==0
                continue;
            end
            if j<length
                if mat(i,j)==mat(i,j+1)
                    mat(i,j)=2.*mat(i,j);
                    mat(i,j+1)=0;
                end
            end
        end
    end
function push(way)
%global
global mat
global length
switch way
    case 1  %up
        for i=1:length
            if mat(i,1)==0
                if rand()>0.5
                    mat(i,1)=2;
                end
            end
        end
    case 2  %down
        for i=1:length
            if mat(i,length)==0
                if rand()>0.5
                    mat(i,length)=2;
                end
            end
        end
    case 3  %left
        for j=1:length
            if mat(length,j)==0
                if rand()>0.5
                    mat(length,j)=2;
                end
            end
        end
    case 4  %right
        for j=1:length
            if mat(1,j)==0
                if rand()>0.5
                    mat(1,j)=2;
                end
            end
        end
end
