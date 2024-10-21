%% Abrir Webacam y hacerla objeto
cam = webcam;

%% carga del archivo de audio y hacer audio un objeto
audio = 'box.mp3';
[a, Fs] = audioread(audio);
box = audioplayer(a, Fs);

%% Tomar primer frame
img1 = snapshot(cam);

%% Convertir el primer frame a BN
fig1BN = rgb2gray(img1);

%% Inicializar el detector de rostros
viola_jones = vision.CascadeObjectDetector(); % Este objeto parte de algoritmo Viola Jones

%% Contador de Frames
wb=waitbar(0,'-','Name','Espera....','CreateCancelBtn','delete(gcbf)' );
i=0;
status = false;
mensaje = false;

%% Comenzar el bucle de los frames
while true
    % Capturar un nuevo frame de la webcam
    img1 = snapshot(cam);
    
    % Convertir el frame actual a escala de grises
    fig2BN = rgb2gray(img1);
    
    % Calcular la diferencia absoluta entre el frame actual y el anterior
    dif = abs(fig2BN - fig1BN);
    
    % Calcular el punto de mayor diferencia
    maxDif = max(dif(:));
    [iReng, iCol] = find(dif == maxDif);
    
    % Detectar caras en el frame actual
    bbox = step(viola_jones, fig2BN);
    
    % Dibujar rectángulos alrededor de las caras detectadas
    if ~isempty(bbox) && mensaje == false
        img1 = insertObjectAnnotation(img1, 'rectangle', bbox, 'Persona');
        fig = uifigure;
        uialert(fig,"Persona detectada.","Alert");
        mensaje = true;
        play(box)
    elseif ~isempty(bbox) && mensaje == true
        img1 = insertObjectAnnotation(img1, 'rectangle', bbox, 'Persona');

    elseif isempty(bbox) && mensaje == true
        mensaje = false;
        close(fig)

    elseif isempty(bbox) && mensaje == false        

    end
    
    % Mostrar el frame con los rectángulos alrededor de las caras detectadas
    imshow(img1);
    
    % Actualizar el frame
    fig1BN = fig2BN;

    if ~ishandle(wb)
        break
    else
        waitbar(i/10, wb, ['num: ' num2str(i)]);
    end
    
    i = i+1;
    pause(0.00000000001);
end
