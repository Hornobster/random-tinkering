trainingSamples = [1 0 0; 1 0 1; 1 1 0; 1 1 1]
desiredOutputs = [1; 1; 1; -1]
weights = [0; 0; 0]

figure(1)

plot(trainingSamples(1:3, 2), trainingSamples(1:3, 3), 'ro', 'MarkerSize', 20)
hold on
plot(trainingSamples(1:3, 2), trainingSamples(1:3, 3), 'o', 'MarkerSize', 1)
axis([-1 2 -1 2])
plot(trainingSamples(4, 2), trainingSamples(4, 3), 'bo', 'MarkerSize', 20)
plot(trainingSamples(4, 2), trainingSamples(4, 3), 'o', 'MarkerSize', 1)

line_old = plot([-1:2], weights(1) + [-1:2]*weights(2) + [-1:2]*weights(3), '-b')

correctlyClassified = 0;

while correctlyClassified < length(desiredOutputs);
    correctlyClassified = 0;
    for i=1:length(desiredOutputs);
        if (dot(weights, trainingSamples(i, :)) > 0);
            rslt = 1;
        else;
            rslt = -1;
        end;
        
        if (desiredOutputs(i) ~= rslt);
            for j=1:length(weights),
                weights(j) = weights(j) + trainingSamples(i, j) * desiredOutputs(i);
            end;
            
            updated_line = plot([-1:2], weights(1) + [-1:2]*weights(2) + [-1:2]*weights(3), '-r');
            delete(line_old);
            line_old = updated_line;
            drawnow;
            pause(1);
        else;
            correctlyClassified = correctlyClassified + 1;
        end;
    end;
end;

disp('New Weights:')
disp(weights)

plot([-1:2], weights(1) + [-1:2]*weights(2) + [-1:2]*weights(3), '-r')
hold off

