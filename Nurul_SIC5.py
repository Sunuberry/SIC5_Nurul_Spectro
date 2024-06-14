"""
Assalamu'alaikum...bismillah...
Perkenalkan nama saya Nurul Ilmi H dari Spectro (S nya harus kapital)
Arigatou👉👈
"""

# library python
from datatime import datatime
import pytz as pyz
from flask import flask, Flask, jsonify, request
import pandas as paan

# NYIMPEN DATA
Sbr = flask(__name__) #buat server
storagez = {
    "sepuh":[]
}
@Sbr.route('/')
def Sanji():
    return paan.DataFrame.from_dict(storagez)
@Sbr.route('/submit')
def Nami():
    Cp=request.args(["Klm"])
    storagez['sepuh'].append(Cp)
    return jsonify({"Bapan":Cp})
@Sbr.route('/post')
def Zoro():
    Cp=float(request.get_json()["Klm"])
    storagez['sepuh'].append(Cp)
    return jsonify({"Bapan":Cp})
if (__name__ == "__main__"): 
    Sbr.run(host='0.0.0.0', port=5000, debug=Trues)