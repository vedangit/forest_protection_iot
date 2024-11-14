// app/api/addSensorData/route.js
import { supabase } from '@/lib/supabaseClient';

export async function POST(request) {
  try {
    // Parse incoming JSON data from the request body
    const data = await request.json();
    const { temperature, humidity, tilt } = data;

    // Log the incoming data to the console
    console.log('Received data:', { temperature, humidity, tilt });

    // Validate incoming data
    if (typeof temperature !== 'number' || typeof humidity !== 'number' || typeof tilt !== 'number') {
      console.error('Invalid input data:', { temperature, humidity, tilt });
      return new Response(JSON.stringify({ error: 'Invalid input data' }), { status: 400 });
    }

    // Log the data validation success
    console.log('Data validation passed');

    // Insert data into the 'sensor_data' table in Supabase
    const { data: sensorData, error } = await supabase
      .from('sensor_data')
      .insert([{ temperature, humidity, tilt }]);

    // Handle any errors during the insert operation
    if (error) {
      console.error('Error inserting data into Supabase:', error);
      return new Response(JSON.stringify({ error: 'Failed to save data' }), { status: 500 });
    }

    // Log the inserted data
    console.log('Data inserted into Supabase:', sensorData);

    // Return the inserted data in the response
    return new Response(JSON.stringify(sensorData), { status: 200 });
  } catch (error) {
    // Catch any unexpected errors
    console.error('Error in API route:', error);
    return new Response(JSON.stringify({ error: 'Server error' }), { status: 500 });
  }
}

export async function GET() {
  try {
    // Fetch data from the 'sensor_data' table in Supabase
    const { data: sensorData, error } = await supabase
      .from('sensor_data')
      .select('*')
      .order('created_at', { ascending: false }); // Optional: order by most recent

    // Handle any errors during data fetching
    if (error) {
      console.error('Error fetching data from Supabase:', error);
      return new Response(JSON.stringify({ error: 'Failed to fetch data' }), { status: 500 });
    }

    // Return the fetched data in the response
    return new Response(JSON.stringify(sensorData), { status: 200 });
  } catch (error) {
    console.error('Error in API route:', error);
    return new Response(JSON.stringify({ error: 'Server error' }), { status: 500 });
  }
}