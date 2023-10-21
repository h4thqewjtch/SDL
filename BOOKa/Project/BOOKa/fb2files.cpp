#include "fb2files.h"

#include <QFile>
#include <QXmlStreamReader>

FB2Files::FB2Files(QObject *parent) : QObject{parent}{}

bool FB2Files::openFB2File(QFile &file, QString *text, QString fontName, int fontSize)
{
    text->clear();
    QString special;
    QString description; // описание
    if( QSysInfo::productType() == "android")
    {
        fontSize *= 1.8;
    }
    QXmlStreamReader streamReader(&file);
    QString rId;
    QString rType;
    QString opt;
    QStringList thisToken;
    QStringList content;
    while(!streamReader.atEnd())
    {
        switch(streamReader.readNext())
        {
        case QXmlStreamReader::StartDocument:
        {
            text->append("<!DOCTYPE HTML><html><body style=\"font-size:%1px; font-family:Sans, ").append(fontName).append(";\">");
            *text = text->arg(fontSize);
            break;
        }
        case QXmlStreamReader::EndDocument:
        {
            text->append("</body></html>");
            break;
        }
        case QXmlStreamReader::StartElement:
        {
            thisToken.append( streamReader.name().toString() );
            if(streamReader.name().toString() == "title")
            {
                content.append(""); // добавляем пункт содержания
                break;
            }
            if( streamReader.name().toString() == "body"
                && !streamReader.attributes().isEmpty()
                && streamReader.attributes().first().value().toString() == "notes")
            {
                special = "notes";  // режим примечаний
            }
            if(special == "notes"
                && streamReader.name().toString() == "section"
                && streamReader.attributes().count() > 0 )
            {
                rId = streamReader.attributes().at(0).value().toString(); // ссылка на текст
                rType = "";
            }
            opt = " align=\"justify\"";
            if(thisToken.contains("title") )
            {
                opt = " align=\"center\" style=\"font-size:" +QString::number(int(fontSize * 1.5)) + "px\" ";
                if(special == "notes")
                {
                    opt += (" id=\"" + rId + "\"");
                }
            }
            if(thisToken.contains("subtitle") )
            {
                opt = " align=\"center\" style=\"font-size:" +QString::number(int(fontSize * 1.2)) + "px\" ";
            }
            if(thisToken.contains("annotation") )
            {
                opt = " align=\"left\" ";
            }
            if(streamReader.name().toString() == "p"
                || streamReader.name().toString() == "subtitle")
            {
                text->append("<p"+opt +" >");
                break;
            }
            if( streamReader.name().toString() == "table" )
            {
                QString table;
                for(int i = 0; i < streamReader.attributes().count(); i++)
                {
                    if(!streamReader.attributes().at(i).name().compare("style"))
                    {
                        table.append( "style=\"" +streamReader.attributes().at(i).value().toString()+ ";\"" );
                    }
                }
                text->append("<table border=1 align=\"center\" style=\"border:solid;\" " + table + ">");
                break;
            }
            if( streamReader.name().toString() == "tr" )
            {
                QString table;
                for(int i = 0; i < streamReader.attributes().count(); i++)
                {
                    if(!streamReader.attributes().at(i).name().compare("aling"))
                    {
                        table.append( "aling=\"" +streamReader.attributes().at(i).value().toString()+ "\"" );
                    }
                }
                text->append("<tr " + table + ">");
                break;
            }
            if( streamReader.name().toString() == "td"
                || streamReader.name().toString() == "th" )
            {
                QString table;
                for(int i = 0; i < streamReader.attributes().count(); i++)
                {
                    if(!streamReader.attributes().at(i).name().compare("aling"))
                    {
                        table.append( "aling=\"" +streamReader.attributes().at(i).value().toString()+ "\" " );
                    }
                    else if(!streamReader.attributes().at(i).name().compare("valing"))
                    {
                        table.append( "valing=\"" +streamReader.attributes().at(i).value().toString()+ "\" " );
                    }
                    else if(!streamReader.attributes().at(i).name().compare("colspan"))
                    {
                        table.append( "colspan=" +streamReader.attributes().at(i).value().toString()+ " " );
                    }
                    else if(!streamReader.attributes().at(i).name().compare("rowspan"))
                    {
                        table.append( "rowspan=" +streamReader.attributes().at(i).value().toString()+ " " );
                    }
                }
                text->append( "<"+streamReader.name().toString()+ " " + table +">" );
                break;
            }
            if( streamReader.name().toString() == "empty-line" )
            {
                text->append("<br/>");
                break;
            }
            if(streamReader.name().toString() == "strong"
                || streamReader.name().toString() == "sup"
                || streamReader.name().toString() == "sub"
                || streamReader.name().toString() == "code"
                || streamReader.name().toString() == "cite")
            {
                text->append( "<" + streamReader.name().toString() + ">");
                break;
            }
            if(streamReader.name().toString() == "emphasis")
            {
                text->append( "<i>" );
                break;
            }
            if( streamReader.name().toString() == "v" )
            {
                text->append("<p align=\"left\" style=\"margin-left:25px;\">");
                break;
            }
            if(streamReader.name().toString() == "strikethrough")
            {
                text->append( "<strike>" );
                break;
            }

            if( streamReader.name().toString() == "a" ) // метка примечания
            {
                rId = "";
                for(int i = 0; i < streamReader.attributes().count(); i++)
                {
                    if(!streamReader.attributes().at(i).name().compare("href"))
                    {
                        rId = streamReader.attributes().at(i).value().toString();
                    }
                }
                text->append("<a href=\"" + rId + "\"> ");
            }
            if(streamReader.name().toString() == "text-author" ) // автор текстта
            {
                text->append( "<p align=\"justify\" style=\"margin-left:45px;\">" );
                break;
            }

            if(streamReader.name().toString() == "date" ) // автор текстта
            {
                text->append( "<p align=\"justify\" style=\"margin-left:45px;\">" );
                break;
            }
            break;
        }
        case QXmlStreamReader::EndElement:
        {
            if( thisToken.last() == streamReader.name().toString() )
            {
                thisToken.removeLast();
            }
            if( streamReader.name().toString() == "p"
                || streamReader.name().toString() == "subtitle"
                || streamReader.name().toString() == "v"
                || streamReader.name().toString() == "date"
                || streamReader.name().toString() == "text-author")
            {
                text->append("</p>");
                break;
            }
            if(streamReader.name().toString() == "td"
                || streamReader.name().toString() == "th"
                || streamReader.name().toString() == "tr"
                || streamReader.name().toString() == "table"
                || streamReader.name().toString() == "sup"
                || streamReader.name().toString() == "sub"
                || streamReader.name().toString() == "strong"
                || streamReader.name().toString() == "code"
                || streamReader.name().toString() == "cite")
            {
                text->append( "</"+streamReader.name().toString()+">" );
                break;
            }
            if( streamReader.name().toString() == "a" )
            {
                rId.remove("#");
                text->append( "</a><span id=\"" + rId + "___" + "\"></span>" );
                break;
            }
            if(streamReader.name().toString() == "emphasis")
            {
                text->append( "</i>" );
                break;
            }
            if(streamReader.name().toString() == "strikethrough")
            {
                text->append( "</strike>" );
                break;
            }
            if(special == "notes") // режим извлечения примечаний
            {
                if( streamReader.name().toString() == "body" )
                {
                    special = "";
                }
                if( streamReader.name().toString() == "section" )
                {
                    text->insert(text->lastIndexOf("<"), "<a href=\"#" + rId + "___" + "\"> см. текст</a>");
                }
            }
            break;
        }
        case QXmlStreamReader::Characters:
        {
            if(thisToken.contains("description")) // ОПИСАНИЕ КНИГИ
            {
                description.append(streamReader.text().toString() + " "); // не выводим
                break;
            }
            if(thisToken.contains( "binary" ) ) // для рисунков
            {
                QString image = "<img src=\"data:"                                                              //////////////////////////////////////////////////////////////////////
                                + rType +";base64,"
                                + streamReader.text().toString()
                                + "\"/>";
                text->replace("#"+rId +"#", image);
                rId = "";
                rType = "";
                break;
            }
            if( thisToken.contains("title") ) // формируем содержание
            {
                content.back() += " " + streamReader.text().toString();
            }
            if(special == "notes" && !thisToken.contains("title") )  // добавление текста примечания
            {
                rType += " ";
                rType += streamReader.text().toString();
            }
            if(thisToken.back() == "p"
                || thisToken.back() == "subtitle"
                || thisToken.back() == "v"
                || thisToken.back() == "emphasis"
                || thisToken.back() == "strong"
                || thisToken.back() == "strikethrough"
                || thisToken.back() == "sup"
                || thisToken.back() == "sub"
                || thisToken.back() == "td"
                || thisToken.back() == "th"
                || thisToken.back() == "code"
                || thisToken.back() == "cite"
                || thisToken.back() == "text-author"  // ??
                || thisToken.back() == "date"
                )
            {
                text->append( streamReader.text().toString() );
                break;
            }
            if(thisToken.back() == "a")
            {
                text->append( streamReader.text().toString() );
                break;
            }
            //все прочие тэги
            if( !streamReader.text().toString().isEmpty() )
            {
                text->append("<span> " + streamReader.text().toString() + "</span>");
            }
            break;
        }
        }
    }

    return true;
}
