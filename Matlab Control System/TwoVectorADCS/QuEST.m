classdef QuEST
    methods(Static)
        function k = NewtonRaphson(proposed_eigen, a, b, c, d, sigma)
            k = proposed_eigen - (proposed_eigen^4 - (a+b)*(proposed_eigen^2) - c*proposed_eigen + ...
                (a*b + c*sigma - d)) / (4*(proposed_eigen^3) - 2*(a+b)*proposed_eigen - c);
        end

        function rot_quat = QuEST_Algorithm(observation_vectors, reference_vectors)
            shape = size(observation_vectors);
            vector_count = shape(1);
            weights = rand(vector_count);
            weights = weights/sum(weights);

            B = zeros(3, 3);
            Z = zeros(1, 3);
            for i = 1:vector_count
                B = B + weights(i) * (observation_vectors(i, :)' * reference_vectors(i, :));
                Z = Z + weights(i) * cross(observation_vectors(i, :),reference_vectors(i, :));
            end
            S = B + B';
            delta = det(S);
            kappa = trace(inv(S)' * delta);
            sigma = 1/2*trace(S);
            d = Z*(S^2)*Z';
            c = delta + Z*S*Z';
            b = sigma^2 + Z*Z';
            a = sigma^2 - kappa;

            proposed_eigen = 1;
            iters = 5;
            for i = 1:iters
                proposed_eigen = QuEST.NewtonRaphson(proposed_eigen, a, b, c, d, sigma);
            end

            alpha = proposed_eigen^2 - sigma^2 + kappa;
            beta = proposed_eigen - sigma;
            gamma = (proposed_eigen + sigma)*alpha - delta;
            X = -(alpha*eye(3) + beta*S + S^2)*Z';
            unscaled_quat = quaternion(gamma, X(1), X(2), X(3));
            rot_quat = 1/sqrt(gamma^2 + (norm(X))^2) * unscaled_quat;
        end
    end
end
