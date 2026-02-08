<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
    <xsl:output method="html" encoding="UTF-8" indent="yes"/>
    <xsl:template match="/">
        <html>
            <head>
                <title>
                    Процессоры
                </title>
                <style>
.books-1 {
    font-size: 40px;
    display: block;
    text-align: center;
}

.inf1 {
    
    margin: 3px 0px 3px 0px
}

.in-nazv {
    font-size: 25px;
    color: blue;
  
    border: 1px solid gray;
}

.in-char,
.in-cen {
    
    border: 1px solid gray;
}

.in-cen {
    font-size: 17px;
    color: red;
}
.in {
    font-size:25px;
    font-weight:bold;
    background:brown;
    color:black;
}
table
{
    border-collapse:collapse;
}
.in-char,in-cen,in-nazv
{font-size:20px;}
                </style>
            </head>
            <body>        
                    <table>
                        <tr class="inf1">
                            <td class="in-nazv in">Название процессора</td>
                            <td class="in-char in">Характеристики</td>
                            <td class="in-cen in">Цена</td>
                        </tr>
                        <xsl:apply-templates select="books/inf">
                            <xsl:sort select="cena" data-type="number" order="ascending"/>
                        </xsl:apply-templates>
                    </table>
            </body>
        </html>
    </xsl:template>
    
    
     <xsl:template match="inf">
        <tr class="inf1">
            <td class="in-nazv">
                <xsl:value-of select="proccesor"/>
            </td>
            <td class="in-char">
                <xsl:value-of select="text1"/>
            </td>
            <td class="in-cen">
                <xsl:value-of select="format-number(cena, '#,##0')"/>
            </td>
        </tr>
    </xsl:template>
</xsl:stylesheet>