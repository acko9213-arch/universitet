<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
    <xsl:output method="html" encoding="UTF-8" indent="yes"/>
    
    <xsl:template match="/">
        <html>
            <head>
                <title><xsl:value-of select="book/names"/></title>
                <style>
                    h1 {
                        text-align: center;
                    }
                    
                    .unit {
                        margin: 3px 0;
                    }
                    
                    .verx-str {
                        font-size: 25px;
                        color: white;
                        background: brown;
                    }
                    
                    th, td {
                        border: 1px solid gray;
                        padding: 5px;
                    }
                    
                    table {
                        border-collapse: collapse;
                        width: 100%;
                    }
                    
                    .niz {
                        color: #c62828;
                        font-weight: bold;
                        border-radius: 4px;
                        text-align: center;
                        display: block;
                    }
                    
                    .verx {
                        color: #2e7d32;
                        font-weight: bold;
                        border-radius: 4px;
                        text-align: center;
                        display: block;
                    }
                    
                    .norm {
                        border-radius: 4px;
                        text-align: center;
                        display: block;
                    }
                </style>
            </head>
            <body>
                <h1><xsl:value-of select="book/names"/></h1>
                
                    <xsl:apply-templates select="book/table"/>
                
            </body>
        </html>
    </xsl:template>
    
    <xsl:template match="table">
        <table>
            <tr class="verx-str">
                <th>ФИО студента</th>
                <th>Мат. анализ</th>
                <th>АЛОВЦМ</th>
                <th>Геометрия</th>
                <th>ОПИ</th>
                <th>ОАП</th>
                <th>Бел яз</th>
                <th>Англ язык</th>
                <th>Физ культ</th>
            </tr>
            <xsl:apply-templates select="unit"/>
        </table>
    </xsl:template>
    
    <xsl:template match="unit">
        <tr class="unit">
            <td class="unit-oz">
                <xsl:value-of select="name"/>
            </td>
            <xsl:apply-templates select="mat"/>
            <xsl:apply-templates select="grinuk"/>
            <xsl:apply-templates select="geom"/>
            <xsl:apply-templates select="opi"/>
            <xsl:apply-templates select="beloded"/>
            <xsl:apply-templates select="bel"/>
            <xsl:apply-templates select="angl"/>
            <xsl:apply-templates select="phizra"/>
        </tr>
    </xsl:template>
    
    <xsl:template match="mat | grinuk | geom | opi | beloded | bel | angl | phizra">
        <td>
            <xsl:variable name="mark" select="."/>
            <xsl:choose>
                <xsl:when test="$mark &lt; 4">
                    <span class="niz">
                        <xsl:value-of select="$mark"/>
                    </span>
                </xsl:when>
                <xsl:when test="$mark &gt;= 9">
                    <span class="verx">
                        <xsl:value-of select="$mark"/>
                    </span>
                </xsl:when>
                <xsl:otherwise>
                    <span class="norm">
                        <xsl:value-of select="$mark"/>
                    </span>
                </xsl:otherwise>
            </xsl:choose>
        </td>
    </xsl:template>
      

</xsl:stylesheet>
