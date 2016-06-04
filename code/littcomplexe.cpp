#include "littcomplexe.h"



littcomplexe::littcomplexe(littcomplexe const& source ){
    this->partIm = source.getPartRe();
    this->partRe = source.getPartIm();
}

littnumber* littcomplexe::operator+(littnumber* a){

           littEntiere* ent1 = dynamic_cast<littEntiere*>(a);

           littrat* rat1 = dynamic_cast<littrat*>(a);

           littReelle* ree1 = dynamic_cast<littReelle*>(a);

           if(ent1!=nullptr)
           {
               littNumerique* res1 = *(this->getPartRe())+ent1;
               littcomplexe* r = new littcomplexe(res1,this->getPartIm());
               return r;
           }else if(rat1!=nullptr){
               littcomplexe* r = new littcomplexe(*(this->getPartRe())+rat1,this->getPartIm());
               return r;
           }else if(ree1!=nullptr){
               littcomplexe* r = new littcomplexe(*(this->getPartRe())+ree1,this->getPartIm());
               return r;
           }

}


littnumber* littcomplexe::operator-(littnumber* a){
   littEntiere* ent1 = dynamic_cast<littEntiere*>(a);

   littrat* rat1 = dynamic_cast<littrat*>(a);

   littReelle* ree1 = dynamic_cast<littReelle*>(a);

   if(ent1!=nullptr)
   {
       littcomplexe* r = new littcomplexe(*(this->getPartRe())-ent1,this->getPartIm());
       return r;
   }else if(rat1!=nullptr){
       littcomplexe* r = new littcomplexe(*(this->getPartRe())-rat1,this->getPartIm());
       return r;
   }else if(ree1!=nullptr){
       littcomplexe* r = new littcomplexe(*(this->getPartRe())-ree1,this->getPartIm());
       return r;
   }
}

littnumber* littcomplexe::operator*(littnumber* a){
   littEntiere* ent1 = dynamic_cast<littEntiere*>(a);

   littrat* rat1 = dynamic_cast<littrat*>(a);

   littReelle* ree1 = dynamic_cast<littReelle*>(a);

   if(ent1!=nullptr)
   {
       littcomplexe* r = new littcomplexe(*(this->getPartRe())*ent1,*(this->getPartIm())*ent1);
       return r;
   }else if(rat1!=nullptr){
       littcomplexe* r = new littcomplexe(*(this->getPartRe())*rat1,*(this->getPartIm())*rat1);
       return r;
   }else if(ree1!=nullptr){
       littcomplexe* r = new littcomplexe(*(this->getPartRe())*ree1,*(this->getPartIm())*ree1);
       return r;
   }
}

littnumber* littcomplexe::operator/(littnumber* a){
   littEntiere* ent1 = dynamic_cast<littEntiere*>(a);

   littrat* rat1 = dynamic_cast<littrat*>(a);

   littReelle* ree1 = dynamic_cast<littReelle*>(a);

   if(ent1!=nullptr)
   {

       littcomplexe* r = new littcomplexe(*(this->getPartRe())/ent1,*(this->getPartIm())/ent1);
       return r;
   }else if(rat1!=nullptr){
       littcomplexe* r = new littcomplexe(*(this->getPartRe())/rat1,*(this->getPartIm())/rat1);
       return r;
   }else if(ree1!=nullptr){
       littcomplexe* r = new littcomplexe(*(this->getPartRe())/ree1,*(this->getPartIm())/ree1);
       return r;
   }
}
