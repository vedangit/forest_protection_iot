'use client'
import React, { useEffect, useState } from 'react';
import { supabase } from '@/lib/supabaseClient';
import { Card, CardContent, Typography, Grid, Box } from '@mui/material';
import { client } from 'websocket';

const TemperatureHumidityCards = () => {
  const [data, setData] = useState({ temperature: null, humidity: null });

  useEffect(() => {
    const fetchData = async () => {
      const { data: sensorData, error } = await supabase
        .from('sensor_data')
        .select('temperature, humidity')
        .order('created_at', { ascending: false }) // Assuming there's a timestamp column to get the latest record
        .limit(1);

      if (error) {
        console.error('Error fetching data:', error);
      } else if (sensorData && sensorData.length > 0) {
        setData(sensorData[0]);
      }
    };

    fetchData();
  }, []);

  return (
    <Box sx={{ padding: '20px' }}>
      <Grid container spacing={2}>
        {/* Temperature Card */}
        <Grid item xs={12} sm={6}>
          <Card sx={{ minWidth: 275 }}>
            <CardContent>
              <Typography variant="h5" component="div">
                Temperature
              </Typography>
              <Typography variant="h4" color="text.secondary">
                {data.temperature !== null ? `${data.temperature}°C` : 'Loading...'}
              </Typography>
            </CardContent>
          </Card>
        </Grid>

        {/* Humidity Card */}
        <Grid item xs={12} sm={6}>
          <Card sx={{ minWidth: 275 }}>
            <CardContent>
              <Typography variant="h5" component="div">
                Humidity
              </Typography>
              <Typography variant="h4" color="text.secondary">
                {data.humidity !== null ? `${data.humidity}%` : 'Loading...'}
              </Typography>
            </CardContent>
          </Card>
        </Grid>
      </Grid>
    </Box>
  );
};

export default TemperatureHumidityCards;
