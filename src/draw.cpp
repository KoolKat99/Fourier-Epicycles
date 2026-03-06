#include <SFML/Graphics.hpp>
#include <cmath>
#include <vector>
#include <complex>
#include <deque>


void draw_rotating_circle() {

    //so for each non zero fourier coeff we create a circle

    sf::RenderWindow window(
        sf::VideoMode(1200, 1000),
        "Rotating Circle"
    );
    window.setFramerateLimit(60);

    sf::Vector2f center(600.f, 500.f);
    double radius = 250.0;
    double radius_2 = 100.0;
    double angle = 0.0;

    // Visual circle (path)
    sf::CircleShape orbit(radius);
    orbit.setOrigin(radius, radius);
    orbit.setPosition(center);
    orbit.setFillColor(sf::Color::Transparent);
    orbit.setOutlineThickness(2);
    orbit.setOutlineColor(sf::Color(100, 100, 100));

    // Point rotating on the circle
    sf::CircleShape point_outside(5.f);
    point_outside.setOrigin(5.f, 5.f);
    point_outside.setFillColor(sf::Color::Red);


    // Point in the center of the circle
    sf::CircleShape point_center(5.f);
    point_center.setOrigin(5.f, 5.f);
    point_center.setFillColor(sf::Color::Blue);


    // Point in the center of the circle
    sf::CircleShape point_2_outside(5.f);
    point_2_outside.setOrigin(5.f, 5.f);
    point_2_outside.setFillColor(sf::Color::Blue);
 


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        angle += 0.005f;

        sf::Vector2f pos(
            center.x + radius * std::cos(angle),
            center.y + radius * std::sin(angle)
        );

        sf::Vector2f pos_2(
            pos.x + radius_2 * std::cos(2.0*angle),
            pos.y + radius_2 * std::sin(2.0*angle)
        );

        sf::Vertex arm[] = {
            sf::Vertex(center, sf::Color::White),
            sf::Vertex(pos,    sf::Color::White)
        };

        sf::Vertex arm_2[] = {
            sf::Vertex(pos, sf::Color::White),
            sf::Vertex(pos_2,    sf::Color::White)
        };


        // Visual circle (path)
        sf::CircleShape orbit_2(radius_2);
        orbit_2.setOrigin(radius_2, radius_2);
        orbit_2.setPosition(pos);
        orbit_2.setFillColor(sf::Color::Transparent);
        orbit_2.setOutlineThickness(2);
        orbit_2.setOutlineColor(sf::Color(100, 100, 100));



        point_outside.setPosition(pos);
        point_center.setPosition(center);
        point_2_outside.setPosition(pos_2);
        window.clear(sf::Color::Black);


        window.draw(orbit);
        window.draw(orbit_2);
        window.draw(arm, 2, sf::Lines);
        window.draw(arm_2, 2, sf::Lines);
        window.display();
    }

}





/*
We need to recursively draw circle epicycles based on the fourier coefficients
each circle will have its own frequency, amplitude, and phase
the first circle will be drawn at the center of the screen
each subsequent circle will be drawn at the end of the previous circle
the final point will trace out the shape

input : Fourier coefficients (vector of form [phase, freq, amplitude]) sorted by freq
return : void
*/
void draw_epicycles(std::vector<std::complex<float>>& coefficients) {
    


    float draw_scale = 400.0f; // pixels per unit

    std::deque<sf::Vector2f> trail; // store previous points
    const int maxTrail = 2000;       // number of points in trail


    //first render the window
    sf::RenderWindow window(
        sf::VideoMode(1200, 1000),
        "Epicycles"
    );
    window.setFramerateLimit(60);

    int N = coefficients.size();

    float angle = 0;
    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        angle += 0.005f;

        sf::Vector2f center(600.f, 500.f);

        //////////////////////////////////
        //////// CLEAR THE WINDOW ///////
        window.clear(sf::Color::Black);
        /////////////////////////////////


        sf::Vector2f pos;


        //dont draw i=0 since constant, doesnt look cool
        for(int i = 1; i < N; ++i) {
            //this should just return fourier coefficient
            //we need to be carefull since we need to include phase then calculate amplitude euclidean norm
            //we probably should do some thresholding so if a coeff < 0.0001 then just ignore it
            std::complex<float> coeff = coefficients[i];
            double amplitude = std::abs(coeff) * draw_scale;
            // if(amplitude < 0.0001f) continue;

            double phase     = std::arg(coeff);
            int freq = (i <= N/2) ? i : i - N;

            //create circle first
            // Visual circle (path)
            sf::CircleShape orbit(amplitude);
            orbit.setOrigin(amplitude, amplitude);
            orbit.setPosition(center);
            orbit.setFillColor(sf::Color::Transparent);
            orbit.setOutlineThickness(2);
            orbit.setOutlineColor(sf::Color(100, 100, 100));


            pos.x = center.x + amplitude * std::cos(freq*angle + phase);
            pos.y = center.y + amplitude * std::sin(freq*angle + phase);

            sf::Vertex arm[] = {
                sf::Vertex(center, sf::Color::White),
                sf::Vertex(pos,    sf::Color::White)
            };


            window.draw(orbit);
            window.draw(arm, 2, sf::Lines);

            //change position
            center = pos;


        }


        //Fading line

        // Add to trail
        trail.push_back(pos);
        if (trail.size() > maxTrail)
            trail.pop_front();


        // Draw trail
        int n = trail.size();
        for (int i = 0; i < n-1; ++i) {
            sf::Vertex line[] = {
                sf::Vertex(trail[i], sf::Color(255, 0, 0, (255 * i)/n)),    // fading red
                sf::Vertex(trail[i+1], sf::Color(255, 0, 0, (255 * (i+1))/n))
            };
            window.draw(line, 2, sf::Lines);
        }






        window.display();

    }
    
}





