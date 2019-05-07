#include <dbconnection.h>

dbConnection::dbConnection(){
   db = QSqlDatabase::addDatabase("QMYSQL");
   db.setHostName("178.128.15.169");
   db.setUserName("snarf");
   db.setPassword("snarfsnarf");
   db.setDatabaseName("chundercats2Dmodeling");
}

bool dbConnection::openConnection(){
    if(db.open()){
        return true;
    }
    return false;
}

void dbConnection::closeConnection(){
    db.close();
}

QString * dbConnection::getShapeTypes(){
    QString * shapes = nullptr;
    if(openConnection()){
        QSqlQuery query("SELECT shape FROM Shape_Type;");
        query.exec();
        shapes = new QString[query.size()];
        qDebug() << query.size();
        int shape = query.record().indexOf("shape");
        int i = 0;
        while (query.next()) {
             shapes[i] = query.value(shape).toString();
             i++;
        }
        closeConnection();
    }
    return shapes;
}

bool dbConnection::createUser(QString user_name,QString password,QString admin_code){
    if(openConnection()){
        QSqlQuery query;
        query.prepare("CALL create_user(:username,:password,:type);");
        query.bindValue(":username", user_name);
        query.bindValue(":password", password);
        if(admin_code == "chunderkitten"){
            query.bindValue(":type", "admin");
        }else{
            query.bindValue(":type","user");
        }
        query.exec();
        if(query.numRowsAffected() > 0){
            return true;
        }
    }
    return false;
}

QString dbConnection::userLogin(QString user_name,QString password){
    if(openConnection()){
        QSqlQuery query;
        query.prepare("CALL user_login(:user_name,:password);");
        query.bindValue(":user_name",user_name);
        query.bindValue(":password",password);
        query.exec();
        int type_index = query.record().indexOf("user_type");
        closeConnection();
        while(query.next()){
            if(query.value(type_index).toString() == "failed"){
                return "Invalid username or password";
            }else{
                return query.value(type_index).toString();
            }
        }
    }
    return "Connection Failed";
}

Shape* dbConnection::createShapeObject(QString shapeType,int id){
    Shape * shape = nullptr;

    if(shapeType == "Line"){
        shape = new Line();
        shape->setID(id);
    }/*else if(shapeType == ){

    }else if(shapeType == ){

    }else if(shapeType == ){

    }else if(shapeType == ){

    }else if(shapeType == ){

    }else if(shapeType == ){

    }else if(shapeType == ){

    }*/

    return shape;
}

const AwesomeVector<Shape*>& dbConnection::getShapes(){
    AwesomeVector<Shape*> shapes;
    Shape::ShapeType test = Shape::ShapeType::Line;
    if(test == Shape::ShapeType::Line){
        qDebug() << "LINE!";
    }
    if(openConnection()){
        QSqlQuery query("CALL get_shapes;");
        query.exec();
        int shape_type_index = query.record().indexOf("shape");
        int id_index = query.record().indexOf("id");
        int x1_index = query.record().indexOf("x1");
        int x2_index = query.record().indexOf("x2");
        int a_index = query.record().indexOf("_a_");
        int b_index = query.record().indexOf("_b_");
        int pen_color_index = query.record().indexOf("pen_color");
        int pen_width_index = query.record().indexOf("pen_width");
        int pen_style_index = query.record().indexOf("pen_style");
        int pen_cap_style_index = query.record().indexOf("pen_cap_style");
        int pen_join_style_index = query.record().indexOf("pen_join_style");
        int brush_color_index = query.record().indexOf("brush_color");
        int brush_style_index = query.record().indexOf("brush_style");
        int text_string_index = query.record().indexOf("text_string");
        int text_color_index = query.record().indexOf("text_color");
        int text_alignment_index = query.record().indexOf("text_alignment");
        int text_point_size_index = query.record().indexOf("text_point_size");
        int text_font_family_index = query.record().indexOf("text_font_family");
        int text_font_style_index = query.record().indexOf("text_font_style");
        int text_font_weight_index = query.record().indexOf("text_font_weight");
        //(query.size());
        int i = 0;
        QString shape_type;
        int shape_id;
        while(query.next()){
           // if(query.value(shape_type_index).toString() == )
            qDebug()<<query.value(shape_type_index).toString();
            shape_type = query.value(shape_type_index).toString();
            shape_id = query.value(id_index).toInt();
            //Shape * ashape = createShapeObject(shape_type,shape_id);
        }
        closeConnection();
    }
    return shapes;
}