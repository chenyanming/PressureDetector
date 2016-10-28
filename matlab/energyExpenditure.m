function [handle]=energyExpenditure (pathStr)

    %fp = fopen('/Users/chandamon/Desktop/TestResults/Test5_5minutes(1-3-1).txt','r');
    fp = fopen(pathStr,'r');
    formatSpec = '%d/%d/%d %d:%d:%d:%d %d %d %d %d';
    format long g

    % read file to array A
    sizeA = [11 Inf];
    A = fscanf(fp,formatSpec,sizeA);
    A = A';

    % size
    [rowSize columnSize] = size(A);
    rowArray = 1:1:rowSize;
    columnArray = 1:1:columnSize;

    % average of four sensor value
    averageSum = A(rowArray,8) + A(rowArray,9) + A(rowArray,10) + A(rowArray,11);

    % standard deviation & Energy Expenditure
    for i = rowArray
        if i+99 <= rowSize
            stanDev(i) = std(averageSum(i:i+99));
            enerExp(i) = 0.282423+stanDev(i)*0.00044;
        end
    end

    % Pressure Value Array for 4 sensors
    sensorOneY = A(rowArray,8);
    sensorTwoY = A(rowArray,9);
    sensorThreeY = A(rowArray,10);
    sensorFourY = A(rowArray,11);

    % Figure 1
    handle(1) = figure('Name','Pressure Value','NumberTitle','off')

    startSeconds = A(1,4)*3600 + A(1,5)*60 + A(1,6) + A(1,7)/1000;
    x = A(rowArray,4)*3600 + A(rowArray,5)*60 + A(rowArray,6) + A(rowArray,7)/1000 - startSeconds;
    plot(x,sensorOneY,x,sensorTwoY,x,sensorThreeY,x,sensorFourY)

    legend('Sensor 1','Sensor 2', 'Sensor 3', 'Sensor 4')
    xlabel('Time(s)','FontSize',15,'FontWeight','bold','Color','r')
    ylabel('Pressure Value','FontSize',15,'FontWeight','bold','Color','r')

    % Figure 2
    handle(2) = figure('Name','Standard Deviation','NumberTitle','off')
    plot(stanDev)
    legend('Standard Deviation')
    ylim([0 inf])

    % Figure 3
    handle(3) = figure('Name','Energy Expenditure','NumberTitle','off')
    plot(enerExp)
    legend('Energy Expenditure')
    ylim([0 inf])


    fclose(fp);
end