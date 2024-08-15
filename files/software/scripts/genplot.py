#!/usr/bin/python
import sys
from pychart import *
theme.get_options()

# usage
# genplot.py <name of input file>

#################### TO BE MODIFIED ###############################
# globals
input_file_name = "sample_file" ## overriden by first argument
num_horiz_elements = 1
num_vertical_elements = 2
format_string = "/a45 A B C\n%s"
labels = ["lu", "bw", "b", "u"]
y_range_start = 0
y_range_end = 200
x_label = "Benchmark"
y_label = "Jitter(us)"
y_tic_interval = 25
locx = 150
locy = 100
legend_rows = 1
## define the styles
st1 = fill_style.Plain(bgcolor=color.blue)
st2 = fill_style.Plain(bgcolor=color.yellow)
st3 = fill_style.Plain(bgcolor=color.green)
st4 = fill_style.Plain(bgcolor=color.red)
st5 = fill_style.Plain(bgcolor=color.ivory)
st6 = fill_style.Plain(bgcolor=color.white)
styles = [st1, st2, st3, st4, st5, st6]

## uncomment for generating a pdf
#theme.output_format = "pdf"
#theme.output_file = "plot.pdf"
#theme.reinitialize()
####################### NEED NOT GO BEYOND THIS LINE ######################

## set the input file name
if ( len(sys.argv) > 1):
    input_file_name = sys.argv[1]

## read file
rows = 0
def read_data(file_name):
    global rows
    file_handle = open(file_name,"r");
    data = []
    for line in file_handle:
    ## sanitize the line
        line = line.rstrip()
        line = line.lstrip()
        if (line == ""):
            continue

        ## split the line
        fields = line.split(" ")
        arr =[] 
        first = 0
        for field in fields:
            field = field.lstrip()
            field = field.rstrip()
            if(field == ""):
                continue
            if (first == 0):
                arr.append(field)
                first = 1
            else :
                arr.append(float(field))
        data.append(tuple(arr))
        rows = rows + 1
    # last line
    file_handle.close()
    return data
data = read_data(input_file_name)

## split the data
data_set = []
for i in range(0, num_vertical_elements):
    data_set.append([])

for row in range(0, rows):
    for i in range(0, num_vertical_elements):
        ds = data_set[i]
        arr = []
        arr.append(data[row][0])
        for j in range (0, num_horiz_elements):
            idx = j * num_vertical_elements + i + 1;
            arr.append(data[row][idx])       
        ds.append(tuple(arr))

#data = [("pip", 20, 30, 5), ("20", 65, 33, 5),
#        ("30", 55, 30, 5), ("40", 45, 51, 7), ("50", 25, 27, 3)]
#data2 = [("pip", 25, 35, 100), ("20", 65, 33, 5),
#        ("30", 55, 30, 5), ("40", 45, 51, 7), ("50", 25, 27, 3)]

# make the chart object
chart_object.set_defaults(area.T, size = (300, 120), y_range = (y_range_start, y_range_end),
                          x_coord = category_coord.T(data, 0))
chart_object.set_defaults(bar_plot.T, data = data)
ar = area.T(x_axis=axis.X(label=x_label, format=format_string),
            y_axis=axis.Y(label=y_label, tic_interval=y_tic_interval),
            legend = legend.T(loc = (locx, locy), nr_rows = legend_rows))

## do the plotting
first = 0
pls = []
for i in range (0,num_vertical_elements):
    # Draw the 1st graph. The Y upper bound is calculated automatically.
    if (first == 0):
        for j in range (0, num_horiz_elements) :
            fill_id = i
            if (num_vertical_elements == 1):
                fill_id = j
            pl = bar_plot.T(label=None, hcol = (j+1), cluster=(j, num_horiz_elements),
                                fill_style=styles[fill_id],data = data_set[i])
            ar.add_plot(pl)
            pls.append(pl)
        first = 1
    ## make the next one
    else :
        new_pls = []
        for j in range (0,  num_horiz_elements) :
            top_plot = bar_plot.T(label=None, hcol = (j+1), stack_on = pls[j], 
                            cluster = (j,num_horiz_elements), fill_style=styles[i], 
                            data=data_set[i])
            ar.add_plot(top_plot)
            new_pls.append(top_plot)
        pls = new_pls

## add the dummy legend
dummy_ds = []
for row in range(0, rows):
    for i in range(0, 1):
        arr = []
        arr.append(data[row][0])
        for j in range (0, num_horiz_elements):
            arr.append(0)       
        dummy_ds.append(tuple(arr))

## put dummy for the legend
if(num_vertical_elements != 1):
    for i in range (0,num_vertical_elements):
        nn = i
        pl = bar_plot.T(label=labels[nn], hcol = (1), cluster=(0, num_horiz_elements),
                                    fill_style=styles[nn],data = dummy_ds)
        ar.add_plot(pl)
else:
    for i in range (0,num_horiz_elements):
        nn = i
        pl = bar_plot.T(label=labels[nn], hcol = (i+1), cluster=(i, num_horiz_elements),
                                    fill_style=styles[nn],data = dummy_ds)
        ar.add_plot(pl)

## finally draw the graph
ar.draw()
