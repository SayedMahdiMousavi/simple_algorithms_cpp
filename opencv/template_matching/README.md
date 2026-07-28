# Template Matching Algorithm

## python

    $ python3 template_matching.py

    Example:
            Enter Path and Name Source Image(Search): ./images/search.png
            Enter Path and Name Target Image(Template): ./images/template.png
            Enter Threshold(float): 0.8
            
            
        Output:
            Max Value: 0.9677860140800476 - Max Loc: (813, 702) / Min Value: -0.6259901523590088

## c++

    $ g++ -std=c++17 template_matching.cpp -o output $(pkg-config --cflags --libs opencv4)
    $ ./output
    
    Example:
            ./output 
