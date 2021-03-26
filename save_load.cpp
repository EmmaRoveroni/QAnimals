#include "save_load.h"
#include "model.h"
QString save_load::datianimali="../QAnimals/data.xml";

save_load::save_load(){}

void save_load::save(const Contenitore<Animale*>& c,dati_finanziari d)
{
    QFile file(datianimali);
    file.open(QIODevice::WriteOnly);
    QXmlStreamWriter xmlStreamWriter(&file);
    xmlStreamWriter.setAutoFormatting(true);
    xmlStreamWriter.writeStartDocument();
    xmlStreamWriter.writeStartElement("animali");
    for(Contenitore<Animale*>::iteratore it=c.begin();it!=c.end() && !c.isEmpty();++it){
        xmlStreamWriter.writeStartElement("animale");
        xmlStreamWriter.writeTextElement("Tipo",QString::fromStdString(c[it].info->getTipo()));
        xmlStreamWriter.writeTextElement("Specie",QString::fromStdString(c[it].info->getSpecie()));
        xmlStreamWriter.writeTextElement("Peso",QString::number(c[it].info->getPeso()));
        xmlStreamWriter.writeTextElement("Altezza",QString::number(c[it].info->getAltezza()));
        xmlStreamWriter.writeTextElement("Lunghezza",QString::number(c[it].info->getLunghezza()));
        xmlStreamWriter.writeTextElement("Eta",QString::number(c[it].info->getEta()));
        if(c[it].info->getInEstinz()) xmlStreamWriter.writeTextElement("InEstinzione","si");
        xmlStreamWriter.writeTextElement("Sede",QString::fromStdString(c[it].info->getSede()));
        if(c[it].info->getTipo() == "Erbivoro"){
               Erbivoro* erb = dynamic_cast<Erbivoro*>(c[it].info);
               vector<Tipo> v = erb->getDieta();
               for(vector<Tipo>::const_iterator it  = v.begin();it != v.end();it++){
                    if((*it)==Frugivoro){
                        xmlStreamWriter.writeTextElement("Frugivoro",QString::fromStdString(erb->getFrugivoro()));
                    }
                    if((*it)==Folivoro){
                        xmlStreamWriter.writeTextElement("Folivoro",QString::fromStdString(erb->getFolivoro()));
                    }
                    if((*it)==Granivoro){
                        xmlStreamWriter.writeTextElement("Granivoro",QString::fromStdString(erb->getGranivoro()));
                    }
                    if((*it)==Nettarivoro){
                        xmlStreamWriter.writeTextElement("Nettarivoro",QString::fromStdString(erb->getNettarivoro()));
                    }
               }
        }
        if(c[it].info->getTipo() == "Carnivoro"){
            Carnivoro* car = dynamic_cast<Carnivoro*>(c[it].info);
            if (car->getvelenoso()) xmlStreamWriter.writeTextElement("Velenoso","E' velenoso");
            if (car->getnecrofago()) xmlStreamWriter.writeTextElement("Necrofago","E' necrofago");
        }
        if(c[it].info->getTipo() == "Onnivoro"){
               Onnivoro* onn = dynamic_cast<Onnivoro*>(c[it].info);
               vector<Tipo> v = onn->getDieta();
               for(vector<Tipo>::const_iterator it  = v.begin();it != v.end();it++){
                    if((*it)==Frugivoro){
                        xmlStreamWriter.writeTextElement("Frugivoro",QString::fromStdString(onn->getFrugivoro()));
                    }
                    if((*it)==Folivoro){
                        xmlStreamWriter.writeTextElement("Folivoro",QString::fromStdString(onn->getFolivoro()));
                    }
                    if((*it)==Granivoro){
                        xmlStreamWriter.writeTextElement("Granivoro",QString::fromStdString(onn->getGranivoro()));
                    }
                    if((*it)==Nettarivoro){
                        xmlStreamWriter.writeTextElement("Nettarivoro",QString::fromStdString(onn->getNettarivoro()));
                    }
               }
               if (onn->getvelenoso()) xmlStreamWriter.writeTextElement("Velenoso","E' velenoso");
               if (onn->getnecrofago()) xmlStreamWriter.writeTextElement("Necrofago","E' necrofago");
        }
        if(c[it].info->getSpecie() == "Rinoceronte"){
            Rinoceronte* rin = dynamic_cast<Rinoceronte*>(c[it].info);
            xmlStreamWriter.writeTextElement("Corno",QString::number(rin->getCorno()));
            if (rin->isGrasso()) xmlStreamWriter.writeTextElement("Grasso","Questo rinoceronte è grasso");
            if (rin->isVecchio()) xmlStreamWriter.writeTextElement("Vecchio","Questo rinoceronte è vecchio");
            if (rin->isdiValore()) xmlStreamWriter.writeTextElement("Divalore","Questo rinoceronte è di valore");
        }
        if(c[it].info->getSpecie() == "Alligatore"){
            Alligatore* all = dynamic_cast<Alligatore*>(c[it].info);
            xmlStreamWriter.writeTextElement("Pelle",QString::number(all->getPelle()));
            if (all->isGrasso()) xmlStreamWriter.writeTextElement("Grasso","Questo alligatore è grasso");
            if (all->isVecchio()) xmlStreamWriter.writeTextElement("Vecchio","Questo alligatore è vecchio");
            if (all->isdiValore()) xmlStreamWriter.writeTextElement("Divalore","Questo alligatore è di valore");
        }
        if(c[it].info->getSpecie() == "Orso"){
            Orso* ors = dynamic_cast<Orso*>(c[it].info);
            xmlStreamWriter.writeTextElement("Pelliccia",QString::number(ors->getPelliccia()));
            if (ors->isGrasso()) xmlStreamWriter.writeTextElement("Grasso","Questo orso è grasso");
            if (ors->isVecchio()) xmlStreamWriter.writeTextElement("Vecchio","Questo orso è vecchio");
            if (ors->isdiValore()) xmlStreamWriter.writeTextElement("Divalore","Questo orso è di valore");
        }
        xmlStreamWriter.writeTextElement("ID",QString::number(c[it].info->getID()));
        xmlStreamWriter.writeEndElement();
    }
    xmlStreamWriter.writeStartElement("DatiFinanziari");
    vector<acquisti> va = d.getListaAcquisti();
    for(vector<acquisti>::iterator it=va.begin();it!=va.end() && !va.empty();++it) {
        xmlStreamWriter.writeStartElement("acquisto");
        xmlStreamWriter.writeTextElement("IDAC",QString::number((*it).getId()));
        xmlStreamWriter.writeTextElement("SpecieAC",QString::fromStdString((*it).getTipoA()));
        xmlStreamWriter.writeTextElement("PrezzoAC",QString::number((*it).getPrezzoA(),'f',2));
        xmlStreamWriter.writeTextElement("DataAC",QString::fromStdString((*it).getData()));
        xmlStreamWriter.writeEndElement();
    }
    vector<vendite> vv = d.getListaVendite();
    for(vector<vendite>::iterator it=vv.begin();it!=vv.end() && !vv.empty();++it) {
        xmlStreamWriter.writeStartElement("vendite");
        xmlStreamWriter.writeTextElement("IDVE",QString::number((*it).getId()));
        xmlStreamWriter.writeTextElement("SpecieVE",QString::fromStdString((*it).getTipoA()));
        xmlStreamWriter.writeTextElement("PrezzoVE",QString::number((*it).getPrezzoV(),'f',2));
        xmlStreamWriter.writeTextElement("DataVE",QString::fromStdString((*it).getData()));
        xmlStreamWriter.writeEndElement();
    }
    xmlStreamWriter.writeStartElement("TotaleAcquisti");
    xmlStreamWriter.writeTextElement("TotAcquisti",(QString::number(d.getTotAcquisti(),'f',2)));
    xmlStreamWriter.writeEndElement();
    xmlStreamWriter.writeStartElement("TotaleVendite");
    xmlStreamWriter.writeTextElement("TotVendite",(QString::number(d.getTotVendite(),'f',2)));
    xmlStreamWriter.writeEndElement();
    xmlStreamWriter.writeStartElement("Bilancio");
    xmlStreamWriter.writeTextElement("Bilanciodato",(QString::number(d.getBilancio(),'f',2)));
    xmlStreamWriter.writeEndElement();
    xmlStreamWriter.writeEndDocument();
    file.close();
}

void save_load::load(Contenitore<Animale*>& c,dati_finanziari& d)
{
    u_int id = 0, eta = 0;
    double peso = 0 , altezza = 0,lunghezza = 0,corno = 0 , pelliccia = 0 , pelle = 0,totacquisti = 0,totvendite = 0 ,
            bilancio = 0,idacquisto = 0 , prezzoacquisto = 0 ,idvendita = 0 ,prezzovendita = 0;
    string tipo = "" , specie = "" , sede = "" , specieacquisto = "" , dataacquisto = "" ,
            specievendita = "" , datavendita = "";
    bool inEstinzione = false,velenoso = false,necrofago = false;
    QFile file(datianimali);
    Animale* animale= 0;
    acquisti* acquisto = 0;
    vendite* vendita = 0;
    vector<Tipo> v;
    if(file.open(QFile::ReadOnly)){
        QXmlStreamReader xmlStreamReader(&file);
        xmlStreamReader.readNext();
        while(!xmlStreamReader.atEnd()){
            if(xmlStreamReader.isStartElement()){
                if(xmlStreamReader.name()=="animali" || xmlStreamReader.name()=="animale" || xmlStreamReader.name()=="DatiFinanziari"||
                   xmlStreamReader.name()=="TotaleAcquisti"|| xmlStreamReader.name()=="TotaleVendite"|| xmlStreamReader.name()=="Bilancio" ){
                                xmlStreamReader.readNext();}
                if(xmlStreamReader.name()=="Tipo") tipo=xmlStreamReader.readElementText().toStdString();
                if(xmlStreamReader.name()=="Specie") specie=xmlStreamReader.readElementText().toStdString();
                if(xmlStreamReader.name()=="Peso") peso=xmlStreamReader.readElementText().toDouble();
                if(xmlStreamReader.name()=="Altezza") altezza=xmlStreamReader.readElementText().toDouble();
                if(xmlStreamReader.name()=="Lunghezza") lunghezza=xmlStreamReader.readElementText().toDouble();
                if(xmlStreamReader.name()=="Eta") eta=xmlStreamReader.readElementText().toUInt();
                if(xmlStreamReader.name()=="InEstinzione") inEstinzione = true;
                if(xmlStreamReader.name()=="Sede") sede = xmlStreamReader.readElementText().toStdString();
                if(xmlStreamReader.name()=="Frugivoro") v.push_back(Frugivoro);
                if(xmlStreamReader.name()=="Folivoro") v.push_back(Folivoro);
                if(xmlStreamReader.name()=="Granivoro") v.push_back(Granivoro);
                if(xmlStreamReader.name()=="Nettarivoro") v.push_back(Nettarivoro);
                if(xmlStreamReader.name()=="Velenoso") velenoso = true;
                if(xmlStreamReader.name()=="Necrofago") necrofago = true;
                if(xmlStreamReader.name()=="Corno") corno=xmlStreamReader.readElementText().toDouble();
                if(xmlStreamReader.name()=="Pelle") pelle=xmlStreamReader.readElementText().toDouble();
                if(xmlStreamReader.name()=="Pelliccia") pelliccia=xmlStreamReader.readElementText().toDouble();
                if(xmlStreamReader.name()=="ID") {
                    id=xmlStreamReader.readElementText().toUInt();
                    if (animale) delete animale;
                    if(specie == "Rinoceronte"){
                        animale = new Rinoceronte(id,peso,altezza,lunghezza,eta,inEstinzione,sede,v,corno);
                    }
                    if(specie == "Alligatore"){
                        animale = new Alligatore(id,peso,altezza,lunghezza,eta,inEstinzione,sede,velenoso,necrofago,pelle);
                    }
                    if(specie == "Orso"){
                        animale = new Orso(id,peso,altezza,lunghezza,eta,inEstinzione,sede,v,velenoso,necrofago,pelliccia);
                    }
                    if(animale){
                        c.push_back(animale);
                        animale = 0;
                        inEstinzione = false;
                        velenoso = false;
                        necrofago = false;
                        v.clear();
                    }
                }
                if(xmlStreamReader.name()=="IDAC") idacquisto = xmlStreamReader.readElementText().toInt();
                if(xmlStreamReader.name()=="SpecieAC") specieacquisto = xmlStreamReader.readElementText().toStdString();
                if(xmlStreamReader.name()=="PrezzoAC") prezzoacquisto = xmlStreamReader.readElementText().toDouble();
                if(xmlStreamReader.name()=="DataAC"){
                    dataacquisto = xmlStreamReader.readElementText().toStdString();
                    if (acquisto) delete acquisto;
                    acquisto = new acquisti(idacquisto,specieacquisto,prezzoacquisto,dataacquisto);
                    if (acquisto){
                        d.DatiFinanziariAggiungiAcquisto(*acquisto);
                        acquisto = 0;
                    }
                }
                if(xmlStreamReader.name()=="IDVE") idvendita = xmlStreamReader.readElementText().toInt();
                if(xmlStreamReader.name()=="SpecieVE") specievendita = xmlStreamReader.readElementText().toStdString();
                if(xmlStreamReader.name()=="PrezzoVE") prezzovendita = xmlStreamReader.readElementText().toDouble();
                if(xmlStreamReader.name()=="DataVE"){
                    datavendita = xmlStreamReader.readElementText().toStdString();
                    if (vendita) delete vendita;
                    vendita = new vendite(idvendita,specievendita,prezzovendita,datavendita);
                    if (vendita){
                        d.DatiFinanziariAggiungiVendita(*vendita);
                        vendita = 0;
                    }
                }
                if(xmlStreamReader.name()=="TotAcquisti"){
                    totacquisti = xmlStreamReader.readElementText().toDouble();
                }
                if(xmlStreamReader.name()=="TotVendite"){
                    totvendite = xmlStreamReader.readElementText().toDouble();
                }
                if(xmlStreamReader.name()=="Bilanciodato"){
                    bilancio = xmlStreamReader.readElementText().toDouble();
                }
            }
            xmlStreamReader.readNext();
     }
     d.DatiFinanziariSetAcquisti(totacquisti);
     d.DatiFinanziariSetVendite(totvendite);
     d.DatiFinanziariSetBilancio(bilancio);
     file.close();
   }
}
