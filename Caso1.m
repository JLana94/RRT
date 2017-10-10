(* ::Package:: *)

(* ::Input:: *)
(*<<"/home/josu/PRM/RRT/RandomData.m"*)


(* ::Input:: *)
(*muestras=1000;*)
(*listaUnifor=Table[RandomData[],{i,muestras}];*)


(* ::Input:: *)
(*Histogram[listaUnifor,20]*)


(* ::Input:: *)
(*lambda=100;*)
(*mu=80;*)
(*ro=0.8;*)


(* ::Input:: *)
(*InterArrivalsTime=Table[RandomExp[lamda],muestras];*)


(* ::Text:: *)
(*InterArrivalsTime lo que calcula realmente es que espacio de tiempo hay entre las llegadas de los paquetes*)


(* ::Input:: *)
(*ArrivalsTimes = Accumulate[InterArrivalsTime];*)


(* ::Text:: *)
(*Acumulas para saber en que tiempo aboslutos estan llegando los paquetes*)


(* ::Input:: *)
(*ServTime=Table[RandomExp[mu],muestras];*)


(* ::Input:: *)
(*FifoSchedulling[arrivals_,service_]:=Module[{n,checkTime},n=1;checkTime=arrivals[[1]];*)
(*Map[(If[checkTime>=#,checkTime+=service[[n++]],checkTime=#+service[[n++]]])&,arrivals]]*)


(* ::Input:: *)
(*Departu=FifoSchedulling[ArrivalsTimes,ServTime];*)


(* ::Input:: *)
(*ListPlot[{ArrivalsTimes[[1;;20]],Departu[[1;;20]]}]*)


(* ::Input:: *)
(*Manipulate[ListPlot[{ArrivalsTimes[[origin;;origin+width]],Departu[[origin;;origin+width]]}],{origin,1,1000-width,1},{width,10,50,1}]*)


(* ::Input:: *)
(*Ahora faltar\[IAcute]a hacer la monta\[NTilde]itas*)
